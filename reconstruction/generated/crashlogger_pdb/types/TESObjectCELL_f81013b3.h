// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectCELL; size 0x148
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BGSWaterCollisionManager__BGSWaterUpdateI_ab74eee1_72076a7c.h"
#include "BSTArray_RE__TESObjectREFR_e1d44341_aef03426.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__TESObjectREFR_std__equal_to_RE__NiPointer_eb7910fc.h"
#include "CellData.h"
#include "ExtraDataList.h"
#include "TESForm.h"
#include "TESFullName.h"
struct BGSLightingTemplate;
struct LOADED_CELL_DATA;
struct NavMeshArray_6d287a4f;
struct TESObjectLAND_8ae461ea;
struct TESWorldSpace;
struct TESObjectCELL_f81013b3 {
    TESForm _base;
    TESFullName _base_TESFullName;
    BSSpinLock grassCreateLock;
    BSSpinLock grassTaskLock;
    unsigned short cellFlags;  // Flag in the PDB is wider than this slot
    unsigned short cellGameFlags;
    unsigned char cellState;  // CellState in the PDB is wider than this slot
    bool autoWaterLoaded;
    bool cellDetached;
    unsigned char pad047;
    ExtraDataList extraList;
    CellData cellData;
    TESObjectLAND_8ae461ea* cellLand;
    float waterHeight;
    unsigned char undefined_7c[4];
    NavMeshArray_6d287a4f* navMeshes;
    BSTScatterTable_RE__BSCRC32_RE__NiPointer_RE__TESObjectREFR_std__equal_to_RE__NiPointer_eb7910fc references;
    TESForm* unk0B0;
    BSTArray_RE__TESObjectREFR_e1d44341_aef03426 objectList;
    BSTArray_void_9eb8914c unk0D0;
    BSTArray_RE__BGSWaterCollisionManager__BGSWaterUpdateI_ab74eee1_72076a7c waterObjects;
    BSTArray_void_9eb8914c unk100;
    BSSpinLock spinLock;
    TESWorldSpace* worldSpace;
    LOADED_CELL_DATA* loadedData;
    BGSLightingTemplate* lightingTemplate;
    unsigned long long unk138;
};
static_assert(sizeof(TESObjectCELL_f81013b3) == 328, "TESObjectCELL_f81013b3 layout differs from the PDB");
