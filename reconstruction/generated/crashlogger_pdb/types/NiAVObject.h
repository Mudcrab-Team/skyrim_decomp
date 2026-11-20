// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAVObject; size 0x110
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_a4a94b8a.h"
#include "NiBound_6900288c.h"
#include "NiObjectNET.h"
#include "NiPointer_RE__NiCollisionObject_8b7c22d3.h"
#include "NiTransform.h"
struct NiNode;
struct TESObjectREFR_b225f218;
struct NiAVObject {
    NiObjectNET _base;
    NiNode* parent;
    unsigned int parentIndex;
    unsigned int unk03C;
    NiPointer_RE__NiCollisionObject_8b7c22d3 collisionObject;
    NiTransform local;
    NiTransform world;
    NiTransform previousWorld;
    NiBound_6900288c worldBound;
    Flag_a4a94b8a flags;
    TESObjectREFR_b225f218* userData;
    float fadeAmount;
    unsigned int lastUpdatedFrameCounter;
    unsigned char lodMode;
    unsigned char flags02;
    unsigned short unk10A;
    unsigned int pad10C;
};
static_assert(sizeof(NiAVObject) == 272, "NiAVObject layout differs from the PDB");
