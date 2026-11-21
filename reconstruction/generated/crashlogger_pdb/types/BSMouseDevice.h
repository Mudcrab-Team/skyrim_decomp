// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMouseDevice; size 0x78
#pragma once

#include "BSInputDevice.h"
struct BSMouseDevice {
    BSInputDevice _base;
    bool backgroundMouse;
    unsigned char undefined_71[7];
};
static_assert(sizeof(BSMouseDevice) == 120, "BSMouseDevice layout differs from the PDB");
