// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionOutput; size 0x30a0
#pragma once

#include "hkPadSpu_hkpConstraintOwner.h"
#include "hkPadSpu_hkpProcessCdPoint.h"
#include "hkPadSpu_hkpProcessCollisionOutput__PotentialInfo.h"
#include "hkpProcessCdPoint.h"
#include "hkpProcessCollisionData__ToiInfo.h"
struct hkpProcessCollisionOutput {
    hkPadSpu_hkpProcessCdPoint m_firstFreeContactPoint_0;
    hkPadSpu_hkpConstraintOwner m_constraintOwner_8;
    hkpProcessCdPoint m_contactPoints_10[256];
    hkpProcessCollisionData__ToiInfo m_toi_3010;
    hkPadSpu_hkpProcessCollisionOutput__PotentialInfo m_potentialContacts_3090;
    char _pad_3098[8];
};
static_assert(sizeof(hkpProcessCollisionOutput) == 12448, "hkpProcessCollisionOutput layout differs from the PDB");
