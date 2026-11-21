// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Semaphore; size 0x10
#pragma once
struct Semaphore {
    void* handle;
    unsigned int size;
    unsigned int capacity;
};
static_assert(sizeof(Semaphore) == 16, "Semaphore layout differs from the PDB");
