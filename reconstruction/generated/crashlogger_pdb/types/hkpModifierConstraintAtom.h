// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpModifierConstraintAtom; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkEnum_hkpConstraintAtom__AtomType_uint16.h"
struct hkpConstraintAtom;
struct hkpModifierConstraintAtom {
    hkEnum_hkpConstraintAtom__AtomType_uint16 m_type_0;
    char _pad_2[14];
    unsigned short m_modifierAtomSize_10;
    unsigned short m_childSize_12;
    char _pad_14[4];
    hkpConstraintAtom* m_child_18;
    unsigned int m_pad_20[2];
    char _pad_28[8];
};
static_assert(sizeof(hkpModifierConstraintAtom) == 48, "hkpModifierConstraintAtom layout differs from the PDB");
