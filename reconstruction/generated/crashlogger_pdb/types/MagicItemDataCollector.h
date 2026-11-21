// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicItemDataCollector; size 0x50
#pragma once

#include "BSTArray_RE__Effect_a9e8f95f.h"
#include "Flags_fa7f7281.h"
#include "MagicItemTraversalFunctor.h"
struct Effect;
struct MagicItemDataCollector {
    MagicItemTraversalFunctor _base;
    BSTArray_RE__Effect_a9e8f95f projectileEffectList;
    Effect* costliestEffect;
    int maxCost;
    unsigned int pad34;
    Effect* largestAreaEffect;
    float highestArea;
    Flags_fa7f7281 flags;
    bool summonsExtraLargeCreature;
    unsigned char pad49;
    unsigned short pad4A;
    unsigned int pad4C;
};
static_assert(sizeof(MagicItemDataCollector) == 80, "MagicItemDataCollector layout differs from the PDB");
