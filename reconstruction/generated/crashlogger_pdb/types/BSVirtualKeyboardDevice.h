// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSVirtualKeyboardDevice; size 0x70
#pragma once

#include "BSKeyboardDevice.h"
struct BSVirtualKeyboardDevice {
    BSKeyboardDevice _base;
};
static_assert(sizeof(BSVirtualKeyboardDevice) == 112, "BSVirtualKeyboardDevice layout differs from the PDB");
