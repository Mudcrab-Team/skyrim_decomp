// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DeferredHideLimb; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPointer_RE__NiNode_28171d5b.h"
struct DeferredHideLimb {
    float dismemberTimer;
    unsigned int limbIndex;
    NiPointer_RE__NiNode_28171d5b dismemberedLimbRoot;
    NiPointer_RE__NiNode_28171d5b replacementLimb;
    DeferredHideLimb* next;
    bool explosion;
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(DeferredHideLimb) == 40, "DeferredHideLimb layout differs from the PDB");
