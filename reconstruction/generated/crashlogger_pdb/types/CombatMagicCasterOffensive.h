// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMagicCasterOffensive; size 0x30
#pragma once

#include "AITimer.h"
#include "CombatMagicCaster.h"
struct CombatMagicCasterOffensive {
    CombatMagicCaster _base;
    AITimer startCastTimer;
    AITimer stopCastTimer;
};
static_assert(sizeof(CombatMagicCasterOffensive) == 48, "CombatMagicCasterOffensive layout differs from the PDB");
