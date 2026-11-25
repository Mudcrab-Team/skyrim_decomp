// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x65c3e0 Main::PumpMessages
// Adapted bodies: none
#include "Main_65c3e0.h"

void Main::PumpMessages()
{
    MSG msg = {};
    while (PeekMessageA(&msg, nullptr, 0, 0, 1)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
}
