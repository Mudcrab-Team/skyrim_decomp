// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPCGamepadDeviceDelegate; size 0xd8
#pragma once

#include "BSGamepadDevice.h"
struct BSPCGamepadDeviceHandler;
struct BSPCGamepadDeviceDelegate {
    BSGamepadDevice _base;
    BSPCGamepadDeviceHandler* gamepadDeviceHandler;
};
static_assert(sizeof(BSPCGamepadDeviceDelegate) == 216, "BSPCGamepadDeviceDelegate layout differs from the PDB");
