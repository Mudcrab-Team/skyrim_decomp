// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContinuousSimulation; size 0x70
#pragma once

#include "hkEnum_hkpSimulation__LastProcessingStep_uint8.h"
struct hkpContinuousSimulation__VFTable;
struct hkpWorld_938ebb10;
struct hkpContinuousSimulation {
    hkpContinuousSimulation__VFTable* vftable_hkpContinuousSimulation_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    unsigned int m_determinismCheckFrameCounter_10;
    char _pad_14[4];
    hkpWorld_938ebb10* m_world_18;
    hkEnum_hkpSimulation__LastProcessingStep_uint8 m_lastProcessingStep_20;
    char _pad_21[3];
    float m_currentTime_24;
    float m_currentPsiTime_28;
    float m_physicsDeltaTime_2C;
    float m_simulateUntilTime_30;
    float m_frameMarkerPsiSnap_34;
    unsigned int m_previousStepResult_38;
    char _pad_3C[52];
};
static_assert(sizeof(hkpContinuousSimulation) == 112, "hkpContinuousSimulation layout differs from the PDB");
