// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MutexRW; size 0x8
#pragma once
struct MutexRW {
    unsigned int CurrentThreadId_0;
    int CurrentLockedCount_4;
};
static_assert(sizeof(MutexRW) == 8, "MutexRW layout differs from the PDB");
