// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSReadWriteLock; size 0x8
#pragma once
struct BSReadWriteLock {
    unsigned int _writerThread;
    unsigned int _lock;
};
static_assert(sizeof(BSReadWriteLock) == 8, "BSReadWriteLock layout differs from the PDB");
