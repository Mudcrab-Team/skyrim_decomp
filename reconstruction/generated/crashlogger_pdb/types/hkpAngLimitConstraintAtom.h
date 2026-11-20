// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAngLimitConstraintAtom; size 0x10
#pragma once

#include "hkpConstraintAtom_c2cbad9c.h"
struct hkpAngLimitConstraintAtom {
    hkpConstraintAtom_c2cbad9c _base;
    bool enabled;
    unsigned char limitAxis;
    float minAngle;
    float maxAngle;
    float angularLimitsTauFactor;
};
static_assert(sizeof(hkpAngLimitConstraintAtom) == 16, "hkpAngLimitConstraintAtom layout differs from the PDB");
