// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAngFrictionConstraintAtom; size 0xc
#pragma once

#include "hkpConstraintAtom_c2cbad9c.h"
struct hkpAngFrictionConstraintAtom {
    hkpConstraintAtom_c2cbad9c _base;
    bool enabled;
    unsigned char firstFrictionAxis;
    unsigned char numFrictionAxes;
    unsigned char undefined_5[3];
    float maxFrictionTorque;
};
static_assert(sizeof(hkpAngFrictionConstraintAtom) == 12, "hkpAngFrictionConstraintAtom layout differs from the PDB");
