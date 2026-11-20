// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatMagicCasterRestore; size 0x30
#pragma once

#include "AITimeStamp.h"
#include "CombatMagicCaster.h"
struct CombatMagicCasterRestore {
    CombatMagicCaster _base;
    AITimeStamp concentrationCastTimeStamp;
    unsigned int unk24;
    unsigned char primaryAV_raw[8];
};
static_assert(sizeof(CombatMagicCasterRestore) == 48, "CombatMagicCasterRestore layout differs from the PDB");
