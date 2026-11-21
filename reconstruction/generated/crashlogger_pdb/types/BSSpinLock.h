// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSpinLock; size 0x8
#pragma once
struct BSSpinLock {
    unsigned int _owningThread;
    unsigned int _lockCount;
};
static_assert(sizeof(BSSpinLock) == 8, "BSSpinLock layout differs from the PDB");
