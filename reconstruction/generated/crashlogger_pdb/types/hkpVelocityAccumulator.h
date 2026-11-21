// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpVelocityAccumulator; size 0x10
#pragma once

#include "hkEnum_hkpVelocityAccumulator__hkpAccumulatorContext_uint8.h"
#include "hkEnum_hkpVelocityAccumulator__hkpAccumulatorType_uint8.h"
struct hkpVelocityAccumulator {
    hkEnum_hkpVelocityAccumulator__hkpAccumulatorType_uint8 m_type_0;
    hkEnum_hkpVelocityAccumulator__hkpAccumulatorContext_uint8 m_context_1;
    char _pad_2[2];
    unsigned int m_deactivationClass_4;
    float m_gravityFactor_8;
    char _pad_C[4];
};
static_assert(sizeof(hkpVelocityAccumulator) == 16, "hkpVelocityAccumulator layout differs from the PDB");
