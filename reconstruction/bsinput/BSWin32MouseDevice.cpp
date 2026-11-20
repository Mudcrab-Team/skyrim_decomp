// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd6edb0 BSWin32MouseDevice::~BSWin32MouseDevice
// 0xe13080 BSWin32MouseDevice::Initialize
// 0xe132b0 BSWin32MouseDevice::Reset
#include "BSWin32MouseDevice.h"
#include <cstring>
BSWin32MouseDevice::BSWin32MouseDevice() {}
BSWin32MouseDevice::~BSWin32MouseDevice() {}

void BSWin32MouseDevice::Reset()
{
    std::memset(&previous, 0, sizeof(previous) + sizeof(next));
}

void BSWin32MouseDevice::Initialize()
{
    std::memset(&previous, 0, sizeof(previous) + sizeof(next));
    dInputDevice = CreateMouseDevice(DirectInputManager, MouseGUID);
    if (!dInputDevice) {
        return;
    }
    backgroundMouse = BackgroundMouseSetting;
    if (BackgroundMouseSetting) {
        dInputDevice->SetCooperativeLevel(GetActiveWindow(), 6);
    } else {
        dInputDevice->SetCooperativeLevel(GetActiveWindow(), 5);
    }
    dInputDevice->SetDataFormat(MouseDataFormat);
}
