// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ShoutMeter; size 0x50
#pragma once

#include "HUDMeter.h"
struct ShoutMeter {
    HUDMeter _base;
    float cooldown;
    unsigned int unk4C;
};
static_assert(sizeof(ShoutMeter) == 80, "ShoutMeter layout differs from the PDB");
