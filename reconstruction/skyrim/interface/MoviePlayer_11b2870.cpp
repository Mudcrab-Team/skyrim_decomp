// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x11b2870 MoviePlayer::Func13_1410A17F0
// Adapted bodies: none
#include "MoviePlayer_11b2870.h"

// Pump pending Win32 messages and return true while playback has not been stopped.
bool MoviePlayer::Func13_1410A17F0()
{
    WinMsg11b2870 msg;
    while (PeekMessageA(&msg, nullptr, 0, 0, 1)) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
    return !stopSequence;
}
