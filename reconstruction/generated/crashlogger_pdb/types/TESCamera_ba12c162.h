// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESCamera; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint2.h"
#include "NiPoint3_a7124070.h"
struct NiNode_9cd97e9e;
struct TESCameraState_b107d5ca;
struct TESCamera__VFTable;
struct TESCamera_ba12c162 {
    TESCamera__VFTable* vftable_TESCamera_0;
    NiPoint2 RotationInput_8;
    NiPoint3_a7124070 TranslationInput_10;
    float ZoomInput_1C;
    NiNode_9cd97e9e* Node_20;
    TESCameraState_b107d5ca* State_28;
    bool Enabled_30;
    char _pad_31[7];
};
static_assert(sizeof(TESCamera_ba12c162) == 56, "TESCamera_ba12c162 layout differs from the PDB");
