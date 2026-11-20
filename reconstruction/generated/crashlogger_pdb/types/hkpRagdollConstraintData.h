// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRagdollConstraintData; size 0x180
#pragma once

#include "Atoms.h"
#include "hkpConstraintData_7581c038.h"
struct hkpRagdollConstraintData {
    hkpConstraintData_7581c038 _base;
    unsigned char undefined_18[8];
    Atoms atoms;
    unsigned char undefined_110[112];
};
static_assert(sizeof(hkpRagdollConstraintData) == 384, "hkpRagdollConstraintData layout differs from the PDB");
