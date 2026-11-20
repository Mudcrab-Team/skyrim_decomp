// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BipedAnim; size 0x2778
// one of 2 different PDB types sharing this name
#pragma once

#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BipedObject.h"
struct NiNode_9cd97e9e;
struct BipedAnim_59e36086 {
    BSIntrusiveRefCounted_8d4cb673 _base;
    unsigned int pad0004;
    NiNode_9cd97e9e* root_08;
    BipedObject Objects_10[42];
    BipedObject BufferedObjects_13C0[42];
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 actorRef;
    unsigned int pad2774;
};
static_assert(sizeof(BipedAnim_59e36086) == 10104, "BipedAnim_59e36086 layout differs from the PDB");
