// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBoxShape; size 0x40
#pragma once

#include "hkVector4.h"
#include "hkpConvexShape.h"
struct hkpBoxShape {
    hkpConvexShape _base;
    unsigned int pad28;
    unsigned int pad2C;
    hkVector4 halfExtents;
};
static_assert(sizeof(hkpBoxShape) == 64, "hkpBoxShape layout differs from the PDB");
