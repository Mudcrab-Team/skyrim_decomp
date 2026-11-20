// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMagicCasterBoundItem; size 0x20
#pragma once

#include "CombatMagicCaster.h"
struct CombatMagicCasterBoundItem {
    CombatMagicCaster _base;
};
static_assert(sizeof(CombatMagicCasterBoundItem) == 32, "CombatMagicCasterBoundItem layout differs from the PDB");
