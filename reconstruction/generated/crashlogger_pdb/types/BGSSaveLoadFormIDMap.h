// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSaveLoadFormIDMap; size 0x68
#pragma once

#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9.h"
struct BGSSaveLoadFormIDMap {
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9 formIDToIndex;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9 indexToFormID;
    unsigned int nextIndex;
    unsigned int pad64;
};
static_assert(sizeof(BGSSaveLoadFormIDMap) == 104, "BGSSaveLoadFormIDMap layout differs from the PDB");
