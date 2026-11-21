// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWin32GamepadDevice; size 0x128
#pragma once

#include "BSPCGamepadDeviceDelegate.h"
#include "XINPUT_STATE.h"
struct BSWin32GamepadDevice {
    BSPCGamepadDeviceDelegate _base;
    XINPUT_STATE previousState;
    float previousLT;
    float previousRT;
    float previousLX;
    float previousLY;
    float previousRX;
    float previousRY;
    XINPUT_STATE currentState;
    float currentLT;
    float currentRT;
    float currentLX;
    float currentLY;
    float currentRX;
    float currentRY;
};
static_assert(sizeof(BSWin32GamepadDevice) == 296, "BSWin32GamepadDevice layout differs from the PDB");
