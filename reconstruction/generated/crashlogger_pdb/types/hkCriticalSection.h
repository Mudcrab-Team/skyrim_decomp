// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkCriticalSection; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "RTL_CRITICAL_SECTION.h"
struct hkCriticalSection {
    RTL_CRITICAL_SECTION m_section_0;
};
static_assert(sizeof(hkCriticalSection) == 40, "hkCriticalSection layout differs from the PDB");
