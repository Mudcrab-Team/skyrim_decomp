// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLimitedForceConstraintMotor; size 0x20
#pragma once

#include "hkpConstraintMotor.h"
struct hkpLimitedForceConstraintMotor {
    hkpConstraintMotor _base;
    float minForce;
    float maxForce;
};
static_assert(sizeof(hkpLimitedForceConstraintMotor) == 32, "hkpLimitedForceConstraintMotor layout differs from the PDB");
