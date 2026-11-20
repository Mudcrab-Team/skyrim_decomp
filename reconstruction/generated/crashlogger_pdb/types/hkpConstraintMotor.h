// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintMotor; size 0x18
#pragma once

#include "hkReferencedObject.h"
struct hkpConstraintMotor {
    hkReferencedObject _base;
    unsigned char type_raw[8];
};
static_assert(sizeof(hkpConstraintMotor) == 24, "hkpConstraintMotor layout differs from the PDB");
