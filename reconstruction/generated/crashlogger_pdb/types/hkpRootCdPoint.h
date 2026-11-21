// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRootCdPoint; size 0x40
#pragma once

#include "hkContactPoint.h"
struct hkpCollidable_9bd4f602;
struct hkpRootCdPoint {
    hkContactPoint contact;
    hkpCollidable_9bd4f602* rootCollidableA;
    unsigned int shapeKeyA;
    unsigned int pad2C;
    hkpCollidable_9bd4f602* rootCollidableB;
    unsigned int shapeKeyB;
    unsigned int pad3C;
};
static_assert(sizeof(hkpRootCdPoint) == 64, "hkpRootCdPoint layout differs from the PDB");
