// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSemaphoreBase; size 0x8
#pragma once
struct BSSemaphoreBase {
    void* semaphore;
};
static_assert(sizeof(BSSemaphoreBase) == 8, "BSSemaphoreBase layout differs from the PDB");
