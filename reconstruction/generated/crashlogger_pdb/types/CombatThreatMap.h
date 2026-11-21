// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CombatThreatMap; size 0x40
#pragma once

#include "BSReadWriteLock.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_aa639d2b.h"
struct CombatThreatMap {
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_aa639d2b threats;
    BSReadWriteLock lock;
    unsigned char lastThreatAddedTimeStamp_raw[8];
};
static_assert(sizeof(CombatThreatMap) == 64, "CombatThreatMap layout differs from the PDB");
