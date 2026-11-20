// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectCELL; size 0x148
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BGSWaterCollisionManager__BGSWaterUpdateI_ab74eee1.h"
#include "BSTArray_RE__TESObjectREFR_e1d44341.h"
#include "BSTArray_void_9eb8914c_e1846db0.h"
#include "BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__TESObjectREFR_std__equal_to_RE__NiPointer_eb7910fc.h"
#include "CellData.h"
#include "ExtraDataList.h"
#include "TESForm_4074aa87.h"
#include "TESFullName_88f61e2a.h"
struct BGSLightingTemplate_493da35d;
struct LOADED_CELL_DATA_cd8cce7f;
struct NavMeshArray;
struct TESObjectLAND;
struct TESWorldSpace_f9563d31;
struct TESObjectCELL {
    TESForm_4074aa87 _base;
    TESFullName_88f61e2a _base_TESFullName;
    BSSpinLock grassCreateLock;
    BSSpinLock grassTaskLock;
    unsigned short cellFlags;  // Flag in the PDB is wider than this slot
    unsigned short cellGameFlags;
    unsigned char cellState;  // CellState in the PDB is wider than this slot
    bool autoWaterLoaded;
    bool cellDetached;
    unsigned char pad047;  // byte in the PDB is wider than this slot
    ExtraDataList extraList;
    CellData cellData;
    TESObjectLAND* cellLand;
    float waterHeight;
    unsigned char undefined_7c[4];
    NavMeshArray* navMeshes;
    BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__TESObjectREFR_std__equal_to_RE__NiPointer_eb7910fc references;
    TESForm_4074aa87* unk0B0;
    BSTArray_RE__TESObjectREFR_e1d44341 objectList;
    BSTArray_void_9eb8914c_e1846db0 unk0D0;
    BSTArray_RE__BGSWaterCollisionManager__BGSWaterUpdateI_ab74eee1 waterObjects;
    BSTArray_void_9eb8914c_e1846db0 unk100;
    BSSpinLock spinLock;
    TESWorldSpace_f9563d31* worldSpace;
    LOADED_CELL_DATA_cd8cce7f* loadedData;
    BGSLightingTemplate_493da35d* lightingTemplate;
    unsigned long long unk138;
};
static_assert(sizeof(TESObjectCELL) == 328, "TESObjectCELL layout differs from the PDB");
