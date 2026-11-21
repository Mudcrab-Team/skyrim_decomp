// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdPoint; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkContactPoint.h"
#include "hkVector4.h"
struct hkpCdBody;
struct hkpCdPoint {
    hkContactPoint contact;
    hkVector4 unweldedNormal;
    hkpCdBody* cdBodyA;
    hkpCdBody* cdBodyB;
};
static_assert(sizeof(hkpCdPoint) == 64, "hkpCdPoint layout differs from the PDB");
