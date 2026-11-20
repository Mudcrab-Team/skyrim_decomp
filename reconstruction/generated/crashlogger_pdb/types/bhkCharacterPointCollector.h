// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterPointCollector; size 0x240
#pragma once

#include "hkpAllCdPointCollector.h"
struct bhkCharacterPointCollector {
    hkpAllCdPointCollector _base;
    unsigned long long unk220;
    unsigned long long unk228;
    unsigned long long unk230;
    unsigned long long unk238;
};
static_assert(sizeof(bhkCharacterPointCollector) == 576, "bhkCharacterPointCollector layout differs from the PDB");
