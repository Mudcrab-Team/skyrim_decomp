// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RaceSexCamera; size 0x58
#pragma once

#include "NiPoint2.h"
#include "NiPoint3_a7124070.h"
struct NiNode_9cd97e9e;
struct RaceSexCamera__VFTable;
struct TESCameraState_b107d5ca;
struct RaceSexCamera {
    RaceSexCamera__VFTable* vftable_RaceSexCamera_0;
    NiPoint2 RotationInput_8;
    NiPoint3_a7124070 TranslationInput_10;
    float ZoomInput_1C;
    NiNode_9cd97e9e* Node_20;
    TESCameraState_b107d5ca* State_28;
    bool Enabled_30;
    char _pad_31[39];
};
static_assert(sizeof(RaceSexCamera) == 88, "RaceSexCamera layout differs from the PDB");
