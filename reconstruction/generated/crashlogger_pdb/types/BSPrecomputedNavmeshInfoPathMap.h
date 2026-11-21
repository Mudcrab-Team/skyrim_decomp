// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSPrecomputedNavmeshInfoPathMap; size 0x48
#pragma once

#include "BSTSingletonExplicit_RE__BSPrecomputedNavmeshInfoPathMap_e0382521.h"
#include "RE__BSTScatterTable_RE__BSCRC32_RE__BSNavmeshInfo_std__equal_to_RE__BSNavmeshInfo_RE__B_4be97887.h"
struct BSPrecomputedNavmeshInfoPathMap {
    BSTSingletonExplicit_RE__BSPrecomputedNavmeshInfoPathMap_e0382521 _base;
    unsigned char undefined_1[23];
    RE__BSTScatterTable_RE__BSCRC32_RE__BSNavmeshInfo_std__equal_to_RE__BSNavmeshInfo_RE__B_4be97887 infoToIndexMap;
};
static_assert(sizeof(BSPrecomputedNavmeshInfoPathMap) == 72, "BSPrecomputedNavmeshInfoPathMap layout differs from the PDB");
