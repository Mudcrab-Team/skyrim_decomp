// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LOADED_REF_DATA; size 0x78
#pragma once

#include "BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee.h"
#include "BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct TESWaterForm_2ffdeaeb;
struct LOADED_REF_DATA {
    BSTArray_void_RE__BSTSmallArrayHeapAllocator_8_cede9fee unk00;
    TESWaterForm_2ffdeaeb* currentWaterType;
    float relevantWaterHeight;
    float cachedRadius;
    unsigned short flags;
    short underwaterCount;
    unsigned int pad2C;
    BSTObjectArena_RE__BSResource__RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNo_79a8f4fc handleList;
    NiPointer_RE__NiAVObject_9e3aa701 data3D;
    void* unk70;
};
static_assert(sizeof(LOADED_REF_DATA) == 120, "LOADED_REF_DATA layout differs from the PDB");
