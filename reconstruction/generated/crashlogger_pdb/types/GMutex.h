// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GMutex; size 0x28
#pragma once

#include "GAcquireInterface.h"
#include "GWaitable.h"
struct GMutexImpl;
struct GMutex {
    GWaitable _base;
    GAcquireInterface _base_GAcquireInterface;
    GMutexImpl* impl;
};
static_assert(sizeof(GMutex) == 40, "GMutex layout differs from the PDB");
