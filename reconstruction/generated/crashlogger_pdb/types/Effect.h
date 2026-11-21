// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Effect; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EffectItem.h"
#include "TESCondition_4d3cdc88.h"
struct EffectSetting_86f4824b;
struct Effect {
    EffectItem effectItem;
    unsigned int pad0C;
    EffectSetting_86f4824b* baseEffect;
    float cost;
    unsigned int pad1C;
    TESCondition_4d3cdc88 conditions;
};
static_assert(sizeof(Effect) == 40, "Effect layout differs from the PDB");
