// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// MoviePlayer, Func13_1410A17F0, stopSequence: CRASHLOGGER_PDB(59818@2026.10.24)
// WinMsg11b2870, unk00, unk41, hwnd, message, wParam, lParam, time, ptX, ptY, PeekMessageA, TranslateMessage, DispatchMessageA: GUESS(low)
// 0x11b2870 MoviePlayer::Func13_1410A17F0
// Adapted bodies: none
#pragma once

#include <cstddef>
#include <cstdint>

struct WinMsg11b2870
{
    void* hwnd;
    std::uint32_t message;
    std::uint64_t wParam;
    std::int64_t lParam;
    std::uint32_t time;
    std::int32_t ptX;
    std::int32_t ptY;
};

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(
    WinMsg11b2870* a_msg,
    void* a_hwnd,
    std::uint32_t a_msgFilterMin,
    std::uint32_t a_msgFilterMax,
    std::uint32_t a_removeMsg);
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const WinMsg11b2870* a_msg);
extern "C" __declspec(dllimport) std::int64_t __stdcall DispatchMessageA(const WinMsg11b2870* a_msg);

class MoviePlayer
{
public:
    bool Func13_1410A17F0();

    std::uint8_t unk00[0x41];
    bool stopSequence;
};

static_assert(sizeof(WinMsg11b2870) == 0x30, "WinMsg11b2870 size");
static_assert(offsetof(MoviePlayer, stopSequence) == 0x41, "stopSequence offset");
