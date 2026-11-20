// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CRITICAL_SECTION; size 0x28
// one of 2 different PDB types sharing this name
#pragma once
struct CRITICAL_SECTION_9c93bfc5 {
    void* debugInfo;
    int lockCount;
    int recursionCount;
    void* owningThread;
    void* lockSemaphore;
    unsigned long long spinCount;
};
static_assert(sizeof(CRITICAL_SECTION_9c93bfc5) == 40, "CRITICAL_SECTION_9c93bfc5 layout differs from the PDB");
