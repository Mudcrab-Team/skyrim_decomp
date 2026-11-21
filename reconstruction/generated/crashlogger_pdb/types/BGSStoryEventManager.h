// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryEventManager; size 0x68
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BGSStoryEvent_39641c46.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9.h"
#include "BSTSingletonImplicit_RE__BGSStoryEventManager_5428935c.h"
struct BGSStoryEventManager {
    BSTSingletonImplicit_RE__BGSStoryEventManager_5428935c _base;
    unsigned char undefined_1[23];
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_3f66aac9 registeredEventIDs;
    BSTArray_RE__BGSStoryEvent_39641c46 events;
    BSSpinLock eventArrayLock;
};
static_assert(sizeof(BGSStoryEventManager) == 104, "BGSStoryEventManager layout differs from the PDB");
