// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFurniture; size 0xf0
#pragma once

#include "ActiveMarker.h"
#include "BSTArray_RE__TESFurniture__EntryPointData_d4dd92a5.h"
#include "TESObjectACTI_e432b98e.h"
#include "WorkBenchData.h"
struct SpellItem_847bf892;
struct TESFurniture {
    TESObjectACTI_e432b98e _base;
    BSTArray_RE__TESFurniture__EntryPointData_d4dd92a5 entryPointDataArray;
    WorkBenchData workBenchData;
    unsigned short padE2;
    ActiveMarker furnFlags;
    SpellItem_847bf892* associatedForm;
};
static_assert(sizeof(TESFurniture) == 240, "TESFurniture layout differs from the PDB");
