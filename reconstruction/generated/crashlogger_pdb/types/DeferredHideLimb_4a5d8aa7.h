// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DeferredHideLimb; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPointer_NiNode_9987ba08.h"
struct DeferredHideLimb_4a5d8aa7 {
    float DismemberTimer_0;
    int LimbIndex_4;
    NiPointer_NiNode_9987ba08 DismemberedLimbRoot_8;
    NiPointer_NiNode_9987ba08 ReplacementLimb_10;
    DeferredHideLimb_4a5d8aa7* Next_18;
    bool Explosion_20;
    char _pad_21[7];
};
static_assert(sizeof(DeferredHideLimb_4a5d8aa7) == 40, "DeferredHideLimb_4a5d8aa7 layout differs from the PDB");
