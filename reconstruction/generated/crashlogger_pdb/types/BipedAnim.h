// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BipedAnim; size 0x2778
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
struct NiNode;
struct BipedAnim {
    BSIntrusiveRefCounted _base;
    unsigned int pad0004;
    NiNode* root;
    unsigned char objects_raw[5040];
    unsigned char bufferedObjects_raw[5040];
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 actorRef;
    unsigned int pad2774;
};
static_assert(sizeof(BipedAnim) == 10104, "BipedAnim layout differs from the PDB");
