// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GColor; size 0x4
#pragma once

#include "ColorData.h"
struct GColor {
    ColorData colorData;
};
static_assert(sizeof(GColor) == 4, "GColor layout differs from the PDB");
