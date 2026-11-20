// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCachingShapePhantom; size 0x1c0
#pragma once

#include "hkArray_RE__hkpCachingShapePhantom__CollisionDetail_dd67749a.h"
#include "hkpShapePhantom.h"
struct hkpCachingShapePhantom {
    hkpShapePhantom _base;
    hkArray_RE__hkpCachingShapePhantom__CollisionDetail_dd67749a collisionDetails;
    bool orderDirty;
    unsigned char undefined_1b1[1];
    unsigned short pad1B2;
    unsigned int pad1B4;
    unsigned long long pad1B8;
};
static_assert(sizeof(hkpCachingShapePhantom) == 448, "hkpCachingShapePhantom layout differs from the PDB");
