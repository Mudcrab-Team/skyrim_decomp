// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSThreadStagesManager; size 0x18
#pragma once

#include "BSStaticArray_RE__BSThreadStages_a41df198.h"
#include "BSTSingletonSDM_RE__BSThreadStagesManager_d21dbc2e.h"
struct BSThreadStagesManager {
    BSTSingletonSDM_RE__BSThreadStagesManager_d21dbc2e _base;
    unsigned char undefined_1[7];
    BSStaticArray_RE__BSThreadStages_a41df198 _base_BSStaticArray_RE_BSThreadStages__;
};
static_assert(sizeof(BSThreadStagesManager) == 24, "BSThreadStagesManager layout differs from the PDB");
