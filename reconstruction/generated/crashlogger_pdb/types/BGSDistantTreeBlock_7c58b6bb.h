// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDistantTreeBlock; size 0x88
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSDistantTreeBlock__TreeGroup_44b5e81d.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_408799cd.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_b87d5198.h"
struct BGSTerrainNode;
struct BGSDistantTreeBlock_7c58b6bb {
    BSTArray_RE__BGSDistantTreeBlock__TreeGroup_44b5e81d treeGroups;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_408799cd instanceMap;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_b87d5198 nextGroup;
    BGSTerrainNode* node;
    bool doneLoading;
    bool attached;
    bool allVisible;
    unsigned char pad83;
    unsigned int pad84;
};
static_assert(sizeof(BGSDistantTreeBlock_7c58b6bb) == 136, "BGSDistantTreeBlock_7c58b6bb layout differs from the PDB");
