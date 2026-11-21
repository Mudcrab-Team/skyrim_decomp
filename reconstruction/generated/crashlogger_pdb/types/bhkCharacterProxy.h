// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterProxy; size 0x260
#pragma once

#include "bhkCharacterPointCollector.h"
#include "bhkSerializable_cf25f762.h"
struct bhkCharacterProxy {
    bhkSerializable_cf25f762 _base;
    bhkCharacterPointCollector ignoredCollisionStartCollector;
};
static_assert(sizeof(bhkCharacterProxy) == 608, "bhkCharacterProxy layout differs from the PDB");
