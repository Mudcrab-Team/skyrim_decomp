// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionData; size 0x3090
#pragma once

#include "hkPadSpu_hkpConstraintOwner.h"
#include "hkPadSpu_hkpProcessCdPoint.h"
#include "hkpProcessCdPoint.h"
#include "hkpProcessCollisionData__ToiInfo.h"
struct hkpProcessCollisionData {
    hkPadSpu_hkpProcessCdPoint m_firstFreeContactPoint_0;
    hkPadSpu_hkpConstraintOwner m_constraintOwner_8;
    hkpProcessCdPoint m_contactPoints_10[256];
    hkpProcessCollisionData__ToiInfo m_toi_3010;
};
static_assert(sizeof(hkpProcessCollisionData) == 12432, "hkpProcessCollisionData layout differs from the PDB");
