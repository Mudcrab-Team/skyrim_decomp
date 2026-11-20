// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCdPoint; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "hkContactPoint_68092cba.h"
#include "hkVector4_f554a678.h"
struct hkpCdBody_cce531ab;
struct hkpCdPoint_ae8f4d2b {
    hkContactPoint_68092cba contact;
    hkVector4_f554a678 unweldedNormal;
    hkpCdBody_cce531ab* cdBodyA;
    hkpCdBody_cce531ab* cdBodyB;
};
static_assert(sizeof(hkpCdPoint_ae8f4d2b) == 64, "hkpCdPoint_ae8f4d2b layout differs from the PDB");
