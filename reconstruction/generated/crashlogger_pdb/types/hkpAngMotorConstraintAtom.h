// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAngMotorConstraintAtom; size 0x18
#pragma once

#include "hkpConstraintAtom_c2cbad9c.h"
struct hkpConstraintMotor;
struct hkpAngMotorConstraintAtom {
    hkpConstraintAtom_c2cbad9c _base;
    bool enabled;
    unsigned char motorAxis;
    short initializedOffset;
    short previousTargetAngleOffset;
    short correspondingAngLimitSolverResultOffset;
    unsigned char undefined_a[2];
    float targetAngle;
    hkpConstraintMotor* motor;
};
static_assert(sizeof(hkpAngMotorConstraintAtom) == 24, "hkpAngMotorConstraintAtom layout differs from the PDB");
