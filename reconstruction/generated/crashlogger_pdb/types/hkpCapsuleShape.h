// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCapsuleShape; size 0x50
#pragma once

#include "hkVector4.h"
#include "hkpConvexShape.h"
struct hkpCapsuleShape {
    hkpConvexShape _base;
    unsigned int pad28;
    unsigned int pad2C;
    hkVector4 vertexA;
    hkVector4 vertexB;
};
static_assert(sizeof(hkpCapsuleShape) == 80, "hkpCapsuleShape layout differs from the PDB");
