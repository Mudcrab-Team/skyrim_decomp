// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LOADED_CELL_DATA; size 0x180
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3.h"
#include "BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8.h"
#include "BSTArray_void_9eb8914c.h"
#include "NiPointer_RE__BSPortalGraph_203711a1.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "NiTMap_RE__BSMultiBoundNode_RE__BSPointerHandle_RE__TESObjectREFR_6f74dc9b.h"
#include "NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_e55926f1.h"
#include "NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiPointer_RE__BSMultiBoundNode_4c25c6fa.h"
#include "NiTMap_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_fa8802ca.h"
struct BGSEncounterZone;
struct LOADED_CELL_DATA {
    NiPointer_RE__BSPortalGraph_203711a1 portalGraph;
    NiPointer_RE__NiNode_28171d5b cell3D;
    NiPointer_RE__NiNode_28171d5b lightMarkerNode;
    NiPointer_RE__NiNode_28171d5b soundMarkerNode;
    NiPointer_RE__NiNode_28171d5b multiBoundNode;
    unsigned long long unk028;
    unsigned long long unk030;
    unsigned long long unk038;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 unk040;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 flickeringLights;
    NiTMap_RE__TESForm_RE__BSPointerHandle_RE__TESObjectREFR_fa8802ca emittanceSourceRefMap;
    NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiNode_e55926f1 emittanceLightRefMap;
    NiTMap_RE__BSPointerHandle_RE__TESObjectREFR_RE__NiPointer_RE__BSMultiBoundNode_4c25c6fa multiboundRefMap;
    NiTMap_RE__BSMultiBoundNode_RE__BSPointerHandle_RE__TESObjectREFR_6f74dc9b refMultiboundMap;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3 activatingRefs;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3 unk100;
    unsigned long long unk110;
    BSTArray_void_9eb8914c unk118;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 decalRefs;
    BSTArray_RE__BSPointerHandle_RE__TESObjectREFR_a12b1937_f051e2e8 skyActors;
    BGSEncounterZone* encounterZone;
    bool decalsQueued;
    unsigned char undefined_169[3];
    int criticalQueuedRefCount;
    int queuedRefCount;
    int queuedDistantRefCount;
    int unk178;
    bool refsFullyLoaded;
    unsigned char undefined_17d[3];
};
static_assert(sizeof(LOADED_CELL_DATA) == 384, "LOADED_CELL_DATA layout differs from the PDB");
