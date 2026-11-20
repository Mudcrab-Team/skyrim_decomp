// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSKeyboardDevice; size 0x70
#pragma once

#include "BSInputDevice.h"
struct BSKeyboardDevice {
    BSInputDevice _base;
};
static_assert(sizeof(BSKeyboardDevice) == 112, "BSKeyboardDevice layout differs from the PDB");
