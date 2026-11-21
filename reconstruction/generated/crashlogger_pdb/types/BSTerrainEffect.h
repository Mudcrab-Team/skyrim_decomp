// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTerrainEffect; size 0xb8
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__BSTerrainEffect__BoneAdjustment_d28a4b95.h"
#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "BSTempEffect.h"
#include "ID.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__bhkWorld_6bd44506.h"
#include "NiQuaternion.h"
struct BSTerrainEffect {
    BSTempEffect _base;
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base_BSTEventSink_RE_PositionPlayerEvent_;
    NiQuaternion orientation;
    NiPoint3 location;
    unsigned int pad54;
    BSTArray_RE__BSTerrainEffect__BoneAdjustment_d28a4b95 terrainAdjustments;
    BSTArray_RE__BSTerrainEffect__BoneAdjustment_d28a4b95 dynamicAdjustments;
    NiPointer_RE__NiAVObject_9e3aa701 model;
    ID modelID;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 target;
    NiPointer_RE__bhkWorld_6bd44506 physicsWorld;
    unsigned int collisionFilter;
    unsigned int padAC;
    NiPointer_RE__NiAVObject_9e3aa701 followNode;
};
static_assert(sizeof(BSTerrainEffect) == 184, "BSTerrainEffect layout differs from the PDB");
