// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NavMeshInfoMap; size 0xf0
#pragma once

#include "BSNavmeshInfoMap.h"
#include "BSReadWriteLock.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_10cfb43a.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_e58b673f.h"
#include "PrecomputedNavmeshInfoPathMap.h"
#include "TESForm.h"
struct NavMeshInfoMap {
    TESForm _base;
    BSNavmeshInfoMap _base_BSNavmeshInfoMap;
    unsigned char undefined_28[8];
    PrecomputedNavmeshInfoPathMap _base_PrecomputedNavmeshInfoPathMap;
    bool updateAll;
    unsigned char pad79;
    unsigned short pad7A;
    unsigned int pad7C;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_10cfb43a infoMap;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_e58b673f ckNavMeshInfoMap;
    BSReadWriteLock mapLock;
    bool init;
    unsigned char padE9;
    unsigned short padEA;
    unsigned int padEC;
};
static_assert(sizeof(NavMeshInfoMap) == 240, "NavMeshInfoMap layout differs from the PDB");
