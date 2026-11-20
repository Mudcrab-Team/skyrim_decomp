// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkp2dAngConstraintAtom; size 0x4
#pragma once

#include "hkpConstraintAtom_c2cbad9c.h"
struct hkp2dAngConstraintAtom {
    hkpConstraintAtom_c2cbad9c _base;
    unsigned char freeRotationAxis;
    unsigned char undefined_3[1];
};
static_assert(sizeof(hkp2dAngConstraintAtom) == 4, "hkp2dAngConstraintAtom layout differs from the PDB");
