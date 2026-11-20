// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPositionConstraintMotor; size 0x30
#pragma once

#include "hkpLimitedForceConstraintMotor.h"
struct hkpPositionConstraintMotor {
    hkpLimitedForceConstraintMotor _base;
    float tau;
    float damping;
    float proportionalRecoveryVelocity;
    float constantRecoveryVelocity;
};
static_assert(sizeof(hkpPositionConstraintMotor) == 48, "hkpPositionConstraintMotor layout differs from the PDB");
