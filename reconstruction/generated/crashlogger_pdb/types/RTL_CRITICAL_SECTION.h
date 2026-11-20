// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _RTL_CRITICAL_SECTION; size 0x28
#pragma once

struct RTL_CRITICAL_SECTION_DEBUG;
struct RTL_CRITICAL_SECTION {
    RTL_CRITICAL_SECTION_DEBUG* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;
    void* LockSemaphore;
    unsigned long long SpinCount;
};
static_assert(sizeof(RTL_CRITICAL_SECTION) == 40, "RTL_CRITICAL_SECTION layout differs from the PDB");
