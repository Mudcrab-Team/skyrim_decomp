// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSetLocalTransformsConstraintAtom; size 0x90
#pragma once

#include "hkTransform_d380b604.h"
#include "hkpConstraintAtom_c2cbad9c.h"
struct hkpSetLocalTransformsConstraintAtom {
    hkpConstraintAtom_c2cbad9c _base;
    unsigned char undefined_2[2];
    unsigned int pad02;
    unsigned char undefined_8[8];
    hkTransform_d380b604 transformA;
    hkTransform_d380b604 transformB;
};
static_assert(sizeof(hkpSetLocalTransformsConstraintAtom) == 144, "hkpSetLocalTransformsConstraintAtom layout differs from the PDB");
