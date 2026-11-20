// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPCOrbisGamepadDevice; size 0x1f8
#pragma once

#include "BSPCGamepadDeviceDelegate.h"
#include "GamepadData.h"
struct BSPCOrbisGamepadDevice {
    BSPCGamepadDeviceDelegate _base;
    GamepadData previousPadState;
    float previousLT;
    float previousRT;
    float previousLX;
    float previousLY;
    float previousRX;
    float previousRY;
    GamepadData currentPadState;
    float currentLT;
    float currentRT;
    float currentLX;
    float currentLY;
    float currentRX;
    float currentRY;
};
static_assert(sizeof(BSPCOrbisGamepadDevice) == 504, "BSPCOrbisGamepadDevice layout differs from the PDB");
