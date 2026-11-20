// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSetupStabilizationAtom; size 0x10
#pragma once

#include "hkpConstraintAtom_c2cbad9c.h"
struct hkpSetupStabilizationAtom {
    hkpConstraintAtom_c2cbad9c _base;
    bool enabled;
    unsigned char undefined_3[1];
    float maxAngle;
    unsigned long long pad08;
};
static_assert(sizeof(hkpSetupStabilizationAtom) == 16, "hkpSetupStabilizationAtom layout differs from the PDB");
