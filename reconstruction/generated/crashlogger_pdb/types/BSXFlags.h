// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSXFlags; size 0x20
#pragma once

#include "NiIntegerExtraData.h"
struct BSXFlags {
    NiIntegerExtraData _base;
};
static_assert(sizeof(BSXFlags) == 32, "BSXFlags layout differs from the PDB");
