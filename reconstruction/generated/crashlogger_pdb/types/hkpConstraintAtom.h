// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintAtom; size 0x2
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkpConstraintAtom__AtomType_uint16.h"
struct hkpConstraintAtom {
    hkEnum_hkpConstraintAtom__AtomType_uint16 m_type_0;
};
static_assert(sizeof(hkpConstraintAtom) == 2, "hkpConstraintAtom layout differs from the PDB");
