// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLinearCastInput; size 0x20
#pragma once

#include "hkVector4.h"
struct hkpLinearCastInput {
    hkVector4 to;
    float maxExtraPenetration;
    float startPointTolerance;
    unsigned long long pad18;
};
static_assert(sizeof(hkpLinearCastInput) == 32, "hkpLinearCastInput layout differs from the PDB");
