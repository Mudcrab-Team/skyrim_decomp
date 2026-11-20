// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpVelocityConstraintMotor; size 0x30
#pragma once

#include "hkpLimitedForceConstraintMotor.h"
struct hkpVelocityConstraintMotor {
    hkpLimitedForceConstraintMotor _base;
    float tau;
    float targetVelocity;
    bool useConstraintTarget;
    unsigned char undefined_29[7];
};
static_assert(sizeof(hkpVelocityConstraintMotor) == 48, "hkpVelocityConstraintMotor layout differs from the PDB");
