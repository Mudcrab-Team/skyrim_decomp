// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterSystem; size 0x130
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__NiPointer_RE__TESWaterDisplacement_1d35ef86.h"
#include "BSTArray_RE__NiPointer_RE__TESWaterNormals_9d0e03f8.h"
#include "BSTArray_RE__NiPointer_RE__TESWaterObject_e8085d47.h"
#include "BSTArray_RE__NiPointer_RE__TESWaterReflections_7fa4a63d.h"
#include "BSTSingletonSDM_RE__TESWaterSystem_ba707ae2.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "NiTPointerList_RE__BSPointerHandle_RE__Actor_3a93a3a5.h"
#include "NiTPointerMap_RE__BSPointerHandle_RE__Actor_RE__WadingWaterData_e5300420.h"
struct BSFixedString_char_83b572b4;
struct TESObjectCELL_f81013b3;
struct TESWaterForm_2ffdeaeb;
struct TESWorldSpace;
struct TESWaterSystem {
    BSTSingletonSDM_RE__TESWaterSystem_ba707ae2 _base;
    unsigned char undefined_1[3];
    unsigned int pad000;
    BSFixedString_char_83b572b4* type;
    unsigned int unk010;
    unsigned int pad014;
    float unk018;
    float unk01C;
    BSTArray_RE__NiPointer_RE__TESWaterObject_e8085d47 waterObjects;
    BSTArray_RE__NiPointer_RE__TESWaterReflections_7fa4a63d waterReflections;
    BSTArray_RE__NiPointer_RE__TESWaterDisplacement_1d35ef86 waterDisplacement;
    BSTArray_RE__NiPointer_RE__TESWaterNormals_9d0e03f8 waterNormals;
    unsigned int unk080;
    NiPoint2_6bdffc9f lastDisplaceOffset;
    unsigned int pad08C;
    NiPointer_RE__NiNode_28171d5b waterRoot;
    TESWaterForm_2ffdeaeb* currentWaterType;
    unsigned int reflectionExteriorCount;
    unsigned int reflectionInteriorCount;
    TESWorldSpace* worldSpace;
    bool enabled;
    unsigned char pad0B1;
    unsigned short pad0B2;
    unsigned int unk0B4;
    bool playerUnderwater;
    bool partiallyUnderwater;
    bool unk0BA;
    unsigned char pad0BB;
    unsigned int lastUpdateFrame;
    float underwaterHeight;
    bool waterRadiusState;
    unsigned char pad0C5;
    unsigned char unk0C6;
    bool showProcedualWater;
    unsigned char unk0C8;
    unsigned char padC9;
    unsigned short padCA;
    int maxActorDisplacement;
    int activeWaterGroups;
    float timeSinceLastRipplePlaced;
    NiTPointerMap_RE__BSPointerHandle_RE__Actor_RE__WadingWaterData_e5300420 wadingWaterData;
    NiTPointerList_RE__BSPointerHandle_RE__Actor_3a93a3a5 actorsInWater;
    bool skipNextUpdate;
    unsigned char pad111;
    unsigned short pad112;
    unsigned int pad114;
    TESObjectCELL_f81013b3* lastWaterCell;
    BSSpinLock lock;
    NiPointer_RE__NiAVObject_9e3aa701 defaultDisplacementWaterObject;
};
static_assert(sizeof(TESWaterSystem) == 304, "TESWaterSystem layout differs from the PDB");
