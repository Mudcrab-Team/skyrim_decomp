// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraWaterData; size 0x28
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "hkRefPtr_RE__hkReferencedObject_80d781c0.h"
struct ActionArray;
struct ExtraWaterData {
    BSExtraData_4ca6af76 _base;
    unsigned long long unk10;
    hkRefPtr_RE__hkReferencedObject_80d781c0 unk18;
    ActionArray* currentArray;
};
static_assert(sizeof(ExtraWaterData) == 40, "ExtraWaterData layout differs from the PDB");
