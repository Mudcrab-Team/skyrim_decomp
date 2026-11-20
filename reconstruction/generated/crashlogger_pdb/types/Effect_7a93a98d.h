// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Effect; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "EffectItem.h"
#include "TESCondition.h"
struct EffectSetting;
struct Effect_7a93a98d {
    EffectItem effectItem;
    unsigned int pad0C;
    EffectSetting* baseEffect;
    float cost;
    unsigned long pad1C;
    TESCondition conditions;
};
static_assert(sizeof(Effect_7a93a98d) == 40, "Effect_7a93a98d layout differs from the PDB");
