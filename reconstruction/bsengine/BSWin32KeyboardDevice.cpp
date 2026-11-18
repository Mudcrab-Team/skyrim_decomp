// Code origin: Reset and Release bodies written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xe12c00 BSWin32KeyboardDevice::Reset
// 0xe12bd0 BSWin32KeyboardDevice::Release
// 0xe12c20 Leafe12c20::Invoke
// 0xe12c30 Leafe12c30::Invoke
#include "BSWin32KeyboardDevice.h"
#include <cstring>
void BSWin32KeyboardDevice::Reset() { std::memset(keyState, 0, sizeof(keyState)); }
void BSWin32KeyboardDevice::Release()
{
    g_directInputManager->ReleaseDevice(device);
    device = nullptr;
}

// RVA 0xe12c20, 3 bytes, BSWin32KeyboardDevice::Unk_09.
void BSWin32KeyboardDevice::Unk_09()
{
}

// RVA 0xe12c30, 3 bytes, BSWin32KeyboardDevice::Unk_0A.
void BSWin32KeyboardDevice::Unk_0A()
{
}
