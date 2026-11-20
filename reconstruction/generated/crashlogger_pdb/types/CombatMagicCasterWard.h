// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMagicCasterWard; size 0x28
#pragma once

#include "AITimer.h"
#include "CombatMagicCaster.h"
struct CombatMagicCasterWard {
    CombatMagicCaster _base;
    AITimer cooldownTimer;
};
static_assert(sizeof(CombatMagicCasterWard) == 40, "CombatMagicCasterWard layout differs from the PDB");
