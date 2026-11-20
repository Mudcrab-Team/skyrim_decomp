// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxTimelineDef; size 0x20
#pragma once

#include "GFxCharacterDef.h"
struct GFxTimelineDef {
    GFxCharacterDef _base;
};
static_assert(sizeof(GFxTimelineDef) == 32, "GFxTimelineDef layout differs from the PDB");
