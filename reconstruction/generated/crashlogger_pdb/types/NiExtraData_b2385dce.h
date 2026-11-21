// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiExtraData; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiObject_de5bc370.h"
struct NiExtraData_b2385dce {
    NiObject_de5bc370 _base;
    BSFixedString_char_83b572b4 name;
};
static_assert(sizeof(NiExtraData_b2385dce) == 24, "NiExtraData_b2385dce layout differs from the PDB");
