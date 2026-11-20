// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionOutput__PotentialInfo; size 0x2010
#pragma once

#include "hkpProcessCollisionOutput__ContactRef.h"
struct hkpProcessCdPoint;
struct hkpProcessCollisionOutput__PotentialInfo {
    hkpProcessCollisionOutput__ContactRef* m_firstFreePotentialContact_0;
    hkpProcessCdPoint** m_firstFreeRepresentativeContact_8;
    hkpProcessCdPoint* m_representativeContacts_10[256];
    hkpProcessCollisionOutput__ContactRef m_potentialContacts_810[256];
};
static_assert(sizeof(hkpProcessCollisionOutput__PotentialInfo) == 8208, "hkpProcessCollisionOutput__PotentialInfo layout differs from the PDB");
