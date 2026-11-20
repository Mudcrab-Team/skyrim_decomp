// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadReferencesMap; size 0x90
#pragma once

#include "BGSCellNumericIDArrayMap.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_5579b1ac.h"
struct BGSSaveLoadReferencesMap {
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9 movedReferences;
    BGSCellNumericIDArrayMap cellReferences;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_5579b1ac worldReferences;
};
static_assert(sizeof(BGSSaveLoadReferencesMap) == 144, "BGSSaveLoadReferencesMap layout differs from the PDB");
