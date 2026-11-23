// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Main, Main::PumpMessages: GUESS(low)
#pragma once

#include <cstdint>

// MSG, PeekMessageA, TranslateMessage, DispatchMessageA: STANDIN GUESS(low); public Win32 names declared locally
struct MSG
{
    void* hwnd;
    uint32_t message;
    uint64_t wParam;
    int64_t lParam;
    uint32_t time;
    int32_t pt[2];
};

extern "C" {
__declspec(dllimport) int __stdcall PeekMessageA(MSG* a_msg, void* a_hwnd, uint32_t a_min, uint32_t a_max, uint32_t a_remove);
__declspec(dllimport) int __stdcall TranslateMessage(const MSG* a_msg);
__declspec(dllimport) int64_t __stdcall DispatchMessageA(const MSG* a_msg);
}

class Main
{
public:
    static void PumpMessages();  // compared: 0x65c3e0
};
