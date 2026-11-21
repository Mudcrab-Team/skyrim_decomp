// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSDirectInputManager; size 0x10
#pragma once

#include "BSTSingletonSDM_RE__BSDirectInputManager_bcf23a98.h"
struct IDirectInput8A;
struct BSDirectInputManager {
    BSTSingletonSDM_RE__BSDirectInputManager_bcf23a98 _base;
    unsigned char undefined_1[3];
    unsigned int pad00;
    IDirectInput8A* diInterface;
};
static_assert(sizeof(BSDirectInputManager) == 16, "BSDirectInputManager layout differs from the PDB");
