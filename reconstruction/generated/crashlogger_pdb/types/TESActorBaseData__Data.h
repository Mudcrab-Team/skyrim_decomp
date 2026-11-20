// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESActorBaseData__Data; size 0x18
#pragma once

#include "TESActorBaseData__Flag.h"
struct TESActorBaseData__Data {
    TESActorBaseData__Flag actorBaseFlags;
    short MagickaOffset_4;
    short StaminaOffset_6;
    unsigned short Level_8;
    unsigned short CalcLevelMin_A;
    unsigned short CalcLevelMax_C;
    unsigned short SpeedMult_E;
    unsigned short BaseDisposition_10;
    unsigned short templateUseFlags;  // TESActorBaseData__TEMPLATE_USE_FLAG in the PDB is wider than this slot
    short HealthOffset_14;
    short BleedoutOverride_16;
};
static_assert(sizeof(TESActorBaseData__Data) == 24, "TESActorBaseData__Data layout differs from the PDB");
