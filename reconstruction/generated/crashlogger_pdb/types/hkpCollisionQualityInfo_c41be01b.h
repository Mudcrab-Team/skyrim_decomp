// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionQualityInfo; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "hkBool.h"
#include "hkPadSpu_int32.h"
struct hkpCollisionQualityInfo_c41be01b {
    float m_keepContact_0;
    float m_create4dContact_4;
    float m_createContact_8;
    float m_manifoldTimDistance_C;
    hkPadSpu_int32 m_useContinuousPhysics_10;
    hkBool m_useSimpleToiHandling_14;
    char _pad_15[3];
    float m_minSeparation_18;
    float m_minExtraSeparation_1C;
    float m_minSafeDeltaTime_20;
    float m_minAbsoluteSafeDeltaTime_24;
    float m_toiSeparation_28;
    float m_toiExtraSeparation_2C;
    float m_toiAccuracy_30;
    float m_maxContraintViolation_34;
    float m_minToiDeltaTime_38;
    unsigned short m_constraintPriority_3C;
    hkBool m_enableToiWeldRejection_3E;
    char _pad_3F;
};
static_assert(sizeof(hkpCollisionQualityInfo_c41be01b) == 64, "hkpCollisionQualityInfo_c41be01b layout differs from the PDB");
