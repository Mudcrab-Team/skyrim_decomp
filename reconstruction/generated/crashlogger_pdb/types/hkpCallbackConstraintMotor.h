// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCallbackConstraintMotor; size 0x48
#pragma once

#include "hkpLimitedForceConstraintMotor.h"
struct hkpCallbackConstraintMotor {
    hkpLimitedForceConstraintMotor _base;
    unsigned char func_raw[8];
    unsigned char callbackType_raw[8];
    unsigned long long userData0;
    unsigned long long userData1;
    unsigned long long userData2;
};
static_assert(sizeof(hkpCallbackConstraintMotor) == 72, "hkpCallbackConstraintMotor layout differs from the PDB");
