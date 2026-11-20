// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSemaphore; size 0x8
#pragma once

#include "BSSemaphoreBase.h"
struct BSSemaphore {
    BSSemaphoreBase _base;
};
static_assert(sizeof(BSSemaphore) == 8, "BSSemaphore layout differs from the PDB");
