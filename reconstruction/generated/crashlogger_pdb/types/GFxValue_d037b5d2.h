// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxValue; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "ValueType.h"
struct GFxValue_d037b5d2 {
    void* ObjectInterface_0;
    ValueType _type;
    unsigned int _pad0C;
    unsigned long long Value_10;
};
static_assert(sizeof(GFxValue_d037b5d2) == 24, "GFxValue_d037b5d2 layout differs from the PDB");
