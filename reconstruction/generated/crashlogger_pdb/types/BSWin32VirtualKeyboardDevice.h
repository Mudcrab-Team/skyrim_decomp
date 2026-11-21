// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWin32VirtualKeyboardDevice; size 0x70
#pragma once

#include "BSVirtualKeyboardDevice.h"
struct BSWin32VirtualKeyboardDevice {
    BSVirtualKeyboardDevice _base;
};
static_assert(sizeof(BSWin32VirtualKeyboardDevice) == 112, "BSWin32VirtualKeyboardDevice layout differs from the PDB");
