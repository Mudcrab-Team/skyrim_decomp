// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAabbPhantom; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkAabb.h"
#include "hkArray_RE__hkpCollidable_93037360.h"
#include "hkpPhantom.h"
struct hkpAabbPhantom {
    hkpPhantom _base;
    hkAabb aabb;
    hkArray_RE__hkpCollidable_93037360 overlappingCollidables;
    bool orderDirty;
    unsigned char pad121[15];
};
static_assert(sizeof(hkpAabbPhantom) == 304, "hkpAabbPhantom layout differs from the PDB");
