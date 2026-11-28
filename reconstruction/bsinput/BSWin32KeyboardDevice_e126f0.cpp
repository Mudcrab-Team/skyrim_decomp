// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0xe126f0 BSWin32KeyboardDevice::Initialize
#include "BSWin32KeyboardDevice_e126f0.h"
#include <cstring>

void BSWin32KeyboardDevice::Initialize()
{
    dInputDevice = gDirectInputManager->CreateDeviceWithGUID(&gGuidSysKeyboard);
    std::memset(keyStates, 0, sizeof(keyStates));
    capsLockOn = false;

    if (dInputDevice) {
        dInputDevice->SetCooperativeLevel(GetForegroundWindow(), 0x15);
        dInputDevice->SetDataFormat(&gKeyboardDataFormat);
        DIPROPDWORD prop;
        prop.size = sizeof(DIPROPDWORD);
        prop.headerSize = 0x10;
        prop.obj = 0;
        prop.how = 0;
        prop.data = 10;
        dInputDevice->SetProperty(1, &prop);
        capsLockOn = (GetKeyState(0x14) & 1) != 0;
    }
}
