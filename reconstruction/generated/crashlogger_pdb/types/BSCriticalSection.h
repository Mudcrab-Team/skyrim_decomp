// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCriticalSection; size 0x28
#pragma once

#include "CRITICAL_SECTION_9c93bfc5.h"
struct BSCriticalSection {
    CRITICAL_SECTION_9c93bfc5 criticalSection;
};
static_assert(sizeof(BSCriticalSection) == 40, "BSCriticalSection layout differs from the PDB");
