// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDynamicPersistenceManager; size 0x28
#pragma once

#include "BSSpinLock.h"
#include "BSTSingletonExplicit_RE__BGSDynamicPersistenceManager_00b076b2.h"
struct BGSDynamicPersistenceManager {
    BSTSingletonExplicit_RE__BGSDynamicPersistenceManager_00b076b2 _base;
    unsigned char undefined_1[23];
    BSSpinLock taskArrayLock;
    int pauseCount;
    unsigned char undefined_24[4];
};
static_assert(sizeof(BGSDynamicPersistenceManager) == 40, "BGSDynamicPersistenceManager layout differs from the PDB");
