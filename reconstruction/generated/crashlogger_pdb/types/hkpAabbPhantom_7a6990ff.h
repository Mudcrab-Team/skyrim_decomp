// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAabbPhantom; size 0x130
// one of 2 different PDB types sharing this name
#pragma once

#include "hkAabb_e8754794.h"
#include "hkArray_RE__hkpCollidable_93037360.h"
#include "hkpPhantom_63a7c629.h"
struct hkpAabbPhantom_7a6990ff {
    hkpPhantom_63a7c629 _base;
    hkAabb_e8754794 aabb;
    hkArray_RE__hkpCollidable_93037360 overlappingCollidables;
    bool orderDirty;
    unsigned char pad121[15];
};
static_assert(sizeof(hkpAabbPhantom_7a6990ff) == 304, "hkpAabbPhantom_7a6990ff layout differs from the PDB");
