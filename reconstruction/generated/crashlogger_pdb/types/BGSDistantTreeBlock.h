// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDistantTreeBlock; size 0x88
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSDistantTreeBlock__TreeGroup_44b5e81d_137c60f7.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_408799cd.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_b87d5198.h"
struct BGSTerrainNode_bd9493dd;
struct BGSDistantTreeBlock {
    BSTArray_RE__BGSDistantTreeBlock__TreeGroup_44b5e81d_137c60f7 treeGroups;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_408799cd instanceMap;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_b87d5198 nextGroup;
    BGSTerrainNode_bd9493dd* node;
    bool doneLoading;
    bool attached;
    bool allVisible;
    unsigned char pad83;
    unsigned int pad84;
};
static_assert(sizeof(BGSDistantTreeBlock) == 136, "BGSDistantTreeBlock layout differs from the PDB");
