// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMember; size 0xc
#pragma once

#include "BSPointerHandle_RE__Actor_1a35f4b9.h"
struct CombatMember {
    BSPointerHandle_RE__Actor_1a35f4b9 memberHandle;
    float groupStrengthUpdateTimer;
    float threatValue;
};
static_assert(sizeof(CombatMember) == 12, "CombatMember layout differs from the PDB");
