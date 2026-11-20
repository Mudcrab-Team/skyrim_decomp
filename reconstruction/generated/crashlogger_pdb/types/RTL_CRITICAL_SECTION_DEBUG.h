// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: _RTL_CRITICAL_SECTION_DEBUG; size 0x30
#pragma once

#include "LIST_ENTRY.h"
struct RTL_CRITICAL_SECTION;
struct RTL_CRITICAL_SECTION_DEBUG {
    unsigned short Type;
    unsigned short CreatorBackTraceIndex;
    unsigned char undefined_4[4];
    RTL_CRITICAL_SECTION* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    unsigned int EntryCount;
    unsigned int ContentionCount;
    unsigned int Flags;
    unsigned short CreatorBackTraceIndexHigh;
    unsigned short Identifier;
};
static_assert(sizeof(RTL_CRITICAL_SECTION_DEBUG) == 48, "RTL_CRITICAL_SECTION_DEBUG layout differs from the PDB");
