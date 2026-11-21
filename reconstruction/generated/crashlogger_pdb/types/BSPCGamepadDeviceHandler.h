// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPCGamepadDeviceHandler; size 0x10
#pragma once

#include "BSIInputDevice.h"
struct BSPCGamepadDeviceDelegate;
struct BSPCGamepadDeviceHandler {
    BSIInputDevice _base;
    BSPCGamepadDeviceDelegate* currentPCGamePadDelegate;
};
static_assert(sizeof(BSPCGamepadDeviceHandler) == 16, "BSPCGamepadDeviceHandler layout differs from the PDB");
