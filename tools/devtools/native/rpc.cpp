#include "rpc.h"

#include <atomic>
#include <chrono>
#include <fstream>
#include <memory>
#include <thread>
#include <httplib.h>

namespace devtools
{
    namespace
    {
        Json Error(const Json& id, int code, const char* message)
        {
            return {{"jsonrpc", "2.0"}, {"id", id},
                    {"error", {{"code", code}, {"message", message}}}};
        }

        Json Call(const std::string& text, const Dispatch& dispatch)
        {
            const auto request = Json::parse(text, nullptr, false);
            if (request.is_discarded()) {
                return Error(nullptr, -32700, "Invalid JSON");
            }
            if (!request.is_object() || !request.contains("id") ||
                !request["id"].is_number_unsigned() || !request.contains("jsonrpc") ||
                request["jsonrpc"] != "2.0" || !request.contains("method") ||
                !request["method"].is_string()) {
                return Error(nullptr, -32600, "Expected a JSON-RPC 2.0 call with a numeric id");
            }
            const auto& id = request["id"];
            const auto params = request.value("params", Json::object());
            if (!params.is_object()) {
                return Error(id, -32602, "Expected named parameters");
            }
            try {
                return {{"jsonrpc", "2.0"}, {"id", id},
                        {"result", dispatch(request["method"].get<std::string>(), params)}};
            } catch (const RpcError& error) {
                return Error(id, error.code, error.message);
            } catch (const Json::exception&) {
                return Error(id, -32602, "Invalid parameters");
            } catch (...) {
                return Error(id, -32603, "Internal error");
            }
        }

        bool TokenMatches(const std::string& presented, const std::string& expected)
        {
            if (presented.size() != expected.size()) {
                return false;
            }
            unsigned int difference = 0;
            for (std::size_t index = 0; index < expected.size(); ++index) {
                difference |= static_cast<unsigned char>(presented[index] ^ expected[index]);
            }
            return difference == 0;
        }
    }

    bool StartServer(int port, std::string token, const std::filesystem::path& transcript, Dispatch dispatch,
                     std::function<void()> closeSession)
    {
        auto log = std::make_shared<std::ofstream>(transcript, std::ios::binary);
        if (!*log) {
            return false;
        }
        auto server = std::make_unique<httplib::Server>();
        auto leased = std::make_shared<std::atomic_bool>(false);
        server->new_task_queue = [] { return new httplib::ThreadPool(2, 2, 4); };
        server->set_read_timeout(3, 0);
        server->set_write_timeout(3, 0);
        server->set_pre_routing_handler(
            [expected = "Bearer " + token, leased](const auto& request, auto& response) {
                if (request.path != "/rpc" || !request.has_header("Upgrade")) {
                    response.status = 404;
                } else if (request.has_header("Origin") ||
                           request.get_header_value_count("Authorization") != 1 ||
                           !TokenMatches(request.get_header_value("Authorization"), expected)) {
                    response.status = 403;
                } else if (*leased) {
                    response.status = 409;
                } else {
                    return httplib::Server::HandlerResponse::Unhandled;
                }
                return httplib::Server::HandlerResponse::Handled;
            });
        server->WebSocket(
            "/rpc", [leased, log, dispatch = std::move(dispatch), closeSession](
                        const httplib::Request&, httplib::ws::WebSocket& socket) {
                if (leased->exchange(true)) {
                    socket.close(httplib::ws::CloseStatus::PolicyViolation);
                    return;
                }

                // A disconnected controller invalidates the run and its fixture state.
                socket.set_read_timeout(30);
                std::string message;
                std::size_t loggedBytes = 0;
                while (socket.read(message) == httplib::ws::ReadResult::Text) {
                    const auto response = Call(message, dispatch);
                    const auto wire = response.dump();
                    if (loggedBytes < 4 * 1024 * 1024) {
                        const auto row = Json{{"request", message}, {"response", response}}.dump(
                            -1, ' ', false, Json::error_handler_t::replace);
                        *log << row << '\n' << std::flush;
                        loggedBytes += row.size() + 1;
                    }
                    const auto sent = socket.send(wire);
                    if (!sent || (response.contains("result") &&
                                  response["result"].is_object() &&
                                  response["result"].value("closing", false))) {
                        break;
                    }
                }
                closeSession();
            });

        if (!server->bind_to_port("127.0.0.1", port)) {
            return false;
        }
        std::thread([leased, closeSession] {
            std::this_thread::sleep_for(std::chrono::seconds(90));
            if (!leased->exchange(true)) {
                closeSession();
            }
        }).detach();
        // The listener lives until the game exits, avoiding thread joins during DLL detach.
        std::thread([listener = server.get()] { listener->listen_after_bind(); }).detach();
        server.release();
        return true;
    }
}
