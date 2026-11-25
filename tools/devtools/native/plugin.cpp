// SPDX-License-Identifier: GPL-3.0-or-later
// COMMUNITY(alandtse/CommonLibSSE-NG@7c27a75da3eb0db080c1f1f63f6df1b7cd733c2a, GPL-3.0-or-later)

#include "rpc.h"

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
#include <Windows.h>

#include <array>
#include <atomic>
#include <charconv>
#include <chrono>
#include <filesystem>
#include <future>
#include <string_view>

namespace
{
    using devtools::Json;
    using devtools::RpcError;
    using namespace std::chrono_literals;

    constexpr std::string_view inventory = "InventoryMenu";
    constexpr std::string_view console = "Console";
    constexpr std::string_view savePath = "Saves\\";
    constexpr char fixture[] = "Fixture";
    constexpr char imageSha[] = "846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f";
    std::atomic_bool dataLoaded = false;
    std::atomic_bool loadCompleted = false;
    std::atomic_bool loadSucceeded = false;
    std::atomic_bool gameTaskQueued = false;
    std::string sessionId;

    // These fields are owned by the UI task queue.
    std::uint64_t sequence = 0;
    std::uint64_t epoch = 0;

    void OnMessage(SKSE::MessagingInterface::Message* message)
    {
        switch (message->type) {
        case SKSE::MessagingInterface::kDataLoaded:
            dataLoaded = true;
            break;
        case SKSE::MessagingInterface::kPreLoadGame:
            loadCompleted = false;
            loadSucceeded = false;
            break;
        case SKSE::MessagingInterface::kPostLoadGame:
            // The message encodes the success flag in the pointer value.
            loadSucceeded = message->data != nullptr;
            loadCompleted = true;
            break;
        default:
            break;
        }
    }

    std::string Environment(const char* name)
    {
        std::array<char, 256> buffer{};
        const auto size = GetEnvironmentVariableA(name, buffer.data(), static_cast<DWORD>(buffer.size()));
        return size && size < buffer.size() ? std::string(buffer.data(), size) : std::string{};
    }

    std::filesystem::path TranscriptPath()
    {
        std::array<wchar_t, 32768> buffer{};
        const auto size = GetEnvironmentVariableW(L"SKYRIM_DEVTOOLS_RUN_DIR", buffer.data(),
                                                  static_cast<DWORD>(buffer.size()));
        if (!size || size >= buffer.size()) {
            return {};
        }
        return std::filesystem::path(buffer.data()) / L"rpc.jsonl";
    }

    bool ForegroundGame()
    {
        DWORD pid = 0;
        GetWindowThreadProcessId(GetForegroundWindow(), &pid);
        return pid == GetCurrentProcessId();
    }

    void RequestClose()
    {
        EnumWindows([](HWND window, LPARAM) -> BOOL {
            DWORD pid = 0;
            GetWindowThreadProcessId(window, &pid);
            if (pid != GetCurrentProcessId() || !IsWindowVisible(window) || GetWindow(window, GW_OWNER)) {
                return TRUE;
            }
            PostMessageW(window, WM_CLOSE, 0, 0);
            return FALSE;
        }, 0);
    }

    bool MovieReady(RE::UI& ui, std::string_view name)
    {
        const auto menu = ui.GetMenu(name);
        return menu && menu->uiMovie && menu->uiMovie->IsAvailable("_root");
    }

    bool Playable(RE::UI& ui)
    {
        if (!loadCompleted || !loadSucceeded || ui.IsMenuOpen("Main Menu") ||
            ui.IsMenuOpen("Loading Menu") || !ui.IsMenuOpen("HUD Menu")) {
            return false;
        }
        const auto player = RE::PlayerCharacter::GetSingleton();
        return player && player->Is3DLoaded();
    }

    Json Snapshot(RE::UI& ui)
    {
        const auto inventoryOpen = ui.IsMenuOpen(inventory);
        const auto consoleOpen = ui.IsMenuOpen(console);
        return {{"seq", ++sequence}, {"loadEpoch", epoch}, {"loadCompleted", loadCompleted.load()},
                {"loadSucceeded", loadSucceeded.load()}, {"playable", Playable(ui)},
                {"mainMenuOpen", ui.IsMenuOpen("Main Menu")},
                {"inventoryOpen", inventoryOpen}, {"inventoryMovieReady", inventoryOpen && MovieReady(ui, inventory)},
                {"consoleOpen", consoleOpen}, {"consoleMovieReady", consoleOpen && MovieReady(ui, console)}};
    }

    void RequireParams(const Json& params, std::initializer_list<const char*> keys)
    {
        if (params.size() != keys.size()) {
            throw RpcError{-32602, "Unexpected parameters"};
        }
        for (const auto key : keys) {
            if (!params.contains(key)) {
                throw RpcError{-32602, "Missing parameter"};
            }
        }
    }

    void RequirePlayable(RE::UI& ui, const Json& suppliedEpoch)
    {
        if (!suppliedEpoch.is_number_unsigned() || suppliedEpoch.get<std::uint64_t>() != epoch) {
            throw RpcError{-32005, "Stale load epoch"};
        }
        if (!Playable(ui)) {
            throw RpcError{-32004, "Fixture is not playable"};
        }
    }

    void TapTab()
    {
        if (!ForegroundGame() || (GetAsyncKeyState(VK_TAB) & 0x8000)) {
            throw RpcError{-32006, "Game is not the foreground window or Tab is held"};
        }
        const auto scan = static_cast<WORD>(MapVirtualKeyW(VK_TAB, MAPVK_VK_TO_VSC));
        INPUT events[2]{};
        events[0].type = events[1].type = INPUT_KEYBOARD;
        events[0].ki.wScan = events[1].ki.wScan = scan;
        events[0].ki.dwFlags = KEYEVENTF_SCANCODE;
        events[1].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        const auto sent = SendInput(2, events, sizeof(INPUT));
        if (sent == 1) {
            SendInput(1, &events[1], sizeof(INPUT));
        }
        if (sent != 2) {
            throw RpcError{-32006, "Windows did not deliver the complete key tap"};
        }
    }

    Json ConsoleQuery()
    {
        const auto log = RE::ConsoleLog::GetSingleton();
        if (!log) {
            throw RpcError{-32007, "Console log is unavailable"};
        }
        // Compare against the preceding buffer so repeated output cannot satisfy a new call.
        const std::string before{std::string_view(log->buffer)};
        RE::Console::ExecuteCommand("GetSKSEVersion");
        const std::string_view after{log->buffer};
        constexpr std::string_view expected = "SKSE64 version: 2.3.1,";
        const bool observed = after.starts_with(before) &&
                              after.substr(before.size()).find(expected) != std::string_view::npos;
        return {{"observed", observed}, {"version", observed ? Json("2.3.1") : Json(nullptr)}};
    }

    Json DispatchOnUI(const std::string& method, const Json& params)
    {
        if (method == "Session.getInfo") {
            RequireParams(params, {});
            return {{"protocol", 1}, {"build", "sse-steam-1-7-104"}, {"imageSha256", imageSha},
                    {"sessionId", sessionId}, {"dataLoaded", dataLoaded.load()},
                    {"capabilities", {"loadFixture", "inventory", "tapTab", "skseVersionQuery"}}};
        }
        if (method == "Session.close") {
            RequireParams(params, {});
            return {{"closing", true}};
        }
        if (method != "Events.snapshot" && method != "Session.loadFixture" &&
            method != "UI.openMenu" && method != "UI.closeMenu" &&
            method != "Input.dispatchKey" && method != "Console.execute") {
            throw RpcError{-32601, "Unknown method"};
        }
        const auto ui = dataLoaded ? RE::UI::GetSingleton() : nullptr;
        if (!ui) {
            throw RpcError{-32004, "Game data is not ready"};
        }
        if (method == "Events.snapshot") {
            RequireParams(params, {});
            return Snapshot(*ui);
        }
        if (method == "Session.loadFixture") {
            RequireParams(params, {"alias"});
            if (params["alias"] != "fixture") {
                throw RpcError{-32602, "Unknown fixture"};
            }
            if (epoch != 0 || !ui->IsMenuOpen("Main Menu")) {
                throw RpcError{-32004, "Fixture can be loaded once from the main menu"};
            }
            const auto settings = RE::INISettingCollection::GetSingleton();
            const auto setting = settings ? settings->GetSetting("sLocalSavePath:General") : nullptr;
            const auto manager = RE::BGSSaveLoadManager::GetSingleton();
            const auto path = setting ? setting->GetString() : nullptr;
            if (!manager || !path || _stricmp(path, savePath.data()) != 0) {
                throw RpcError{-32004, "Isolated save path is unavailable"};
            }
            ++epoch;
            manager->Load(fixture);
            return {{"loadEpoch", epoch}};
        }

        if (method == "UI.openMenu" || method == "UI.closeMenu") {
            RequireParams(params, {"name", "loadEpoch"});
            RequirePlayable(*ui, params["loadEpoch"]);
            const auto name = params["name"].get<std::string>();
            if (name != inventory && name != console) {
                throw RpcError{-32602, "Unsupported menu"};
            }
            const bool opening = method == "UI.openMenu";
            if (ui->IsMenuOpen(name) != opening) {
                const auto queue = RE::UIMessageQueue::GetSingleton();
                if (!queue) {
                    throw RpcError{-32004, "Menu queue is unavailable"};
                }
                queue->AddMessage(RE::BSFixedString(name),
                                  opening ? RE::UI_MESSAGE_TYPE::kShow : RE::UI_MESSAGE_TYPE::kHide, nullptr);
            }
            return {{"accepted", true}};
        }
        if (method == "Input.dispatchKey") {
            RequireParams(params, {"key", "phase", "loadEpoch"});
            RequirePlayable(*ui, params["loadEpoch"]);
            if (params["key"] != "Tab" || params["phase"] != "tap" || !ui->IsMenuOpen(inventory) ||
                ui->IsMenuOpen(console)) {
                throw RpcError{-32602, "Only a Tab tap in Inventory is supported"};
            }
            TapTab();
            return {{"accepted", true}};
        }
        if (method == "Console.execute") {
            RequireParams(params, {"command", "loadEpoch"});
            RequirePlayable(*ui, params["loadEpoch"]);
            if (params["command"] != "GetSKSEVersion" || !ui->IsMenuOpen(console) || !MovieReady(*ui, console)) {
                throw RpcError{-32602, "Only GetSKSEVersion in the ready console is supported"};
            }
            return ConsoleQuery();
        }
        throw RpcError{-32601, "Unknown method"};
    }

    Json Dispatch(const std::string& method, const Json& params)
    {
        if (method == "Session.getInfo" || method == "Session.close") {
            return DispatchOnUI(method, params);
        }
        struct Pending
        {
            std::atomic_bool claimed = false;
            std::promise<Json> response;
        };
        auto pending = std::make_shared<Pending>();
        auto result = pending->response.get_future();
        if (gameTaskQueued.exchange(true)) {
            throw RpcError{-32008, "A UI task is still pending"};
        }
        SKSE::GetTaskInterface()->AddUITask([pending, method, params] {
            if (pending->claimed.exchange(true)) {
                gameTaskQueued = false;
                return;
            }
            try {
                auto response = DispatchOnUI(method, params);
                gameTaskQueued = false;
                pending->response.set_value(std::move(response));
            } catch (...) {
                gameTaskQueued = false;
                pending->response.set_exception(std::current_exception());
            }
        });
        if (result.wait_for(4s) != std::future_status::ready) {
            pending->claimed = true;
            throw RpcError{-32008, "UI task timed out"};
        }
        return result.get();
    }
}

SKSE_PLUGIN_VERSION = [] {
    SKSE::PluginVersionData version{};
    version.PluginVersion(REL::Version{1, 0, 0, 0});
    version.PluginName("SkyrimDevTools");
    version.CompatibleVersions({SKSE::RUNTIME_SSE_1_7_104});
    return version;
}();

SKSE_PLUGIN_LOAD(const SKSE::LoadInterface* skse)
{
    if (skse->RuntimeVersion() != SKSE::RUNTIME_SSE_1_7_104 ||
        skse->SKSEVersion() != REL::Version{2, 3, 1, 0}.pack()) {
        return false;
    }

    std::string token = Environment("SKYRIM_DEVTOOLS_TOKEN");
    sessionId = Environment("SKYRIM_DEVTOOLS_SESSION");
    if (token.empty() && sessionId.empty()) {
        return true;
    }
    const auto portText = Environment("SKYRIM_DEVTOOLS_PORT");
    const auto transcript = TranscriptPath();
    int port = 0;
    const auto parsed = std::from_chars(portText.data(), portText.data() + portText.size(), port);
    if (parsed.ec != std::errc{} || parsed.ptr != portText.data() + portText.size() ||
        token.size() != 64 || sessionId.size() != 32 || port < 1024 || port > 65535 || transcript.empty() ||
        Environment("SKYRIM_DEVTOOLS_IMAGE") != imageSha) {
        return false;
    }

    SKSE::Init(skse, SKSE::InitInfo{.log = false});
    const auto messages = SKSE::GetMessagingInterface();
    if (!messages || !SKSE::GetTaskInterface() || !messages->RegisterListener(OnMessage)) {
        return false;
    }
    return devtools::StartServer(port, std::move(token), transcript, Dispatch, RequestClose);
}
