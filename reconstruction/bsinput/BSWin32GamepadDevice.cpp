// Code origin: Reset and Initialize bodies written from the local listings; declarations and stand-in layout added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0xe7b060 BSWin32GamepadDevice::Reset
// 0xe7ad60 BSWin32GamepadDevice::Initialize
// 0xe7b050 Leafe7b050::Invoke
// 0xe7b080 Leafe7b080::Invoke
// 0xe12430 BSWin32GamepadDevice::~BSWin32GamepadDevice
#include "BSWin32GamepadDevice.h"
#include <cstring>
BSWin32GamepadDevice::~BSWin32GamepadDevice() {}
void BSWin32GamepadDevice::Reset() { std::memset(state, 0, sizeof(state)); }
void BSWin32GamepadDevice::Initialize()
{
    g_gamepadManager->Unk_ceed20(0);
    std::memset(state, 0, sizeof(state));
}

// RVA 0xe7b050, 3 bytes
void BSWin32GamepadDevice::Release()
{
}

// RVA 0xe7b080, 3 bytes
void BSWin32GamepadDevice::SetRumble(float lValue, float rValue)
{
}
