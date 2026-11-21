// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: OverrideData; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__UnloadedRefData_e3fb16fa.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTSetTraits_un_75743c02.h"
struct OverrideData {
    BSTArray_RE__UnloadedRefData_e3fb16fa addedData;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTSetTraits_un_75743c02 removedData;
};
static_assert(sizeof(OverrideData) == 72, "OverrideData layout differs from the PDB");
