// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LOADED_CELL_DATA; size 0x180
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937.h"
#include "BSTArray_void_7a93e7a7.h"
#include "NiPointer_RE__BSPortalGraph_203711a1.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "NiTMap_RE__BSMultiBoundNode_RE__BSPointerHandle_RE__TESObjectREFR_6f74dc9b.h"
#include "NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_e55926f1.h"
#include "NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiPointer_RE__BSMultiBoundNode_4c25c6fa.h"
#include "NiTMap_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_fa8802ca.h"
struct BGSEncounterZone_a1aa56ae;
struct LOADED_CELL_DATA_cd8cce7f {
    NiPointer_RE__BSPortalGraph_203711a1 portalGraph;
    NiPointer_RE__NiNode_28171d5b cell3D;
    NiPointer_RE__NiNode_28171d5b lightMarkerNode;
    NiPointer_RE__NiNode_28171d5b soundMarkerNode;
    NiPointer_RE__NiNode_28171d5b multiBoundNode;
    unsigned long long unk028;
    unsigned long long unk030;
    unsigned long long unk038;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937 unk040;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937 flickeringLights;
    NiTMap_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_fa8802ca emittanceSourceRefMap;
    NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_e55926f1 emittanceLightRefMap;
    NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiPointer_RE__BSMultiBoundNode_4c25c6fa multiboundRefMap;
    NiTMap_RE__BSMultiBoundNode_RE__BSPointerHandle_RE__TESObjectREFR_6f74dc9b refMultiboundMap;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12 activatingRefs;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12 unk100;
    unsigned long long unk110;
    BSTArray_void_7a93e7a7 fld118;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937 decalRefs;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937 skyActors;
    BGSEncounterZone_a1aa56ae* encounterZone;
    bool decalsQueued;
    unsigned char undefined_169[3];
    int criticalQueuedRefCount;
    int queuedRefCount;
    int queuedDistantRefCount;
    int hideLODTime;
    bool refsFullyLoaded;
    unsigned char undefined_17d[3];
};
static_assert(sizeof(LOADED_CELL_DATA_cd8cce7f) == 384, "LOADED_CELL_DATA_cd8cce7f layout differs from the PDB");
