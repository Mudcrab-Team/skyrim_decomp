// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSpringDamperConstraintMotor; size 0x28
#pragma once

#include "hkpLimitedForceConstraintMotor.h"
struct hkpSpringDamperConstraintMotor {
    hkpLimitedForceConstraintMotor _base;
    float springConstant;
    float springDamping;
};
static_assert(sizeof(hkpSpringDamperConstraintMotor) == 40, "hkpSpringDamperConstraintMotor layout differs from the PDB");
