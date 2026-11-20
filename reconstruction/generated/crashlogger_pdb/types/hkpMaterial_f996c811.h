// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMaterial; size 0xc
// one of 2 different PDB types sharing this name
#pragma once

#include "hkEnum_hkpMaterial__ResponseType_int8.h"
#include "hkHalf.h"
struct hkpMaterial_f996c811 {
    hkEnum_hkpMaterial__ResponseType_int8 m_responseType_0;
    char _pad_1;
    hkHalf m_rollingFrictionMultiplier_2;
    float m_friction_4;
    float m_restitution_8;
};
static_assert(sizeof(hkpMaterial_f996c811) == 12, "hkpMaterial_f996c811 layout differs from the PDB");
