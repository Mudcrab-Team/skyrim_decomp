// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellItem::Data; size 0x28
#pragma once

#include "SpellItem__SpellFlag.h"
struct BGSPerk;
struct SpellItem__Data {
    int CostOverride_0;
    SpellItem__SpellFlag flags;
    int SpellType_8;
    float ChargeTime_C;
    int CastingType_10;
    int Delivery_14;
    float CastDuration_18;
    float Range_1C;
    BGSPerk* CastingPerk_20;
};
static_assert(sizeof(SpellItem__Data) == 40, "SpellItem__Data layout differs from the PDB");
