// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CRITICAL_SECTION; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct RTL_CRITICAL_SECTION_DEBUG;
struct CRITICAL_SECTION {
    RTL_CRITICAL_SECTION_DEBUG* DebugInfo_0;
    int LockCount_8;
    int RecursionCount_C;
    void* OwningThread_10;
    void* LockSemaphore_18;
    unsigned long long SpinCount_20;
};
static_assert(sizeof(CRITICAL_SECTION) == 40, "CRITICAL_SECTION layout differs from the PDB");
