// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkWorldCinfo; size 0x100
#pragma once

#include "hkpWorldCinfo.h"
struct bhkWorldCinfo {
    hkpWorldCinfo _base;
};
static_assert(sizeof(bhkWorldCinfo) == 256, "bhkWorldCinfo layout differs from the PDB");
