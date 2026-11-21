// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleShapePhantom; size 0x1c0
#pragma once

#include "hkArray_RE__hkpCollidable_93037360.h"
#include "hkpShapePhantom.h"
struct hkpSimpleShapePhantom {
    hkpShapePhantom _base;
    hkArray_RE__hkpCollidable_93037360 collisionDetails;
    bool orderDirty;
    unsigned char pad1B1[15];
};
static_assert(sizeof(hkpSimpleShapePhantom) == 448, "hkpSimpleShapePhantom layout differs from the PDB");
