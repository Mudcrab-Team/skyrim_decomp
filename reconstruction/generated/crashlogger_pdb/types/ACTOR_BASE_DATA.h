// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ACTOR_BASE_DATA; size 0x18
#pragma once

#include "Flag_a4a94b8a.h"
struct ACTOR_BASE_DATA {
    Flag_a4a94b8a actorBaseFlags;
    short magickaOffset;
    short staminaOffset;
    unsigned short level;
    unsigned short calcLevelMin;
    unsigned short calcLevelMax;
    unsigned short speedMult;
    unsigned short baseDisposition;
    unsigned short templateUseFlags;  // TEMPLATE_USE_FLAG in the PDB is wider than this slot
    short healthOffset;
    short bleedoutOverride;
};
static_assert(sizeof(ACTOR_BASE_DATA) == 24, "ACTOR_BASE_DATA layout differs from the PDB");
