// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Mutex; size 0x8
#pragma once
struct Mutex {
    unsigned int CurrentThreadId_0;
    int CurrentLockedCount_4;
};
static_assert(sizeof(Mutex) == 8, "Mutex layout differs from the PDB");
