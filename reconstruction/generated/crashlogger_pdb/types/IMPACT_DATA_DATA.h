// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMPACT_DATA_DATA; size 0x18
#pragma once

#include "ORIENTATION.h"
#include "SOUND_LEVEL.h"
struct IMPACT_DATA_DATA {
    float effectDuration;
    ORIENTATION orient;
    float angleThreshold;
    float placementRadius;
    SOUND_LEVEL soundLevel;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char resultOverride;  // ImpactResult in the PDB is wider than this slot
    unsigned short unk16;
};
static_assert(sizeof(IMPACT_DATA_DATA) == 24, "IMPACT_DATA_DATA layout differs from the PDB");
