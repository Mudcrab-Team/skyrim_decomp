// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraLock; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct REFR_LOCK;
struct ExtraLock {
    BSExtraData_4ca6af76 _base;
    REFR_LOCK* lock;
};
static_assert(sizeof(ExtraLock) == 24, "ExtraLock layout differs from the PDB");
