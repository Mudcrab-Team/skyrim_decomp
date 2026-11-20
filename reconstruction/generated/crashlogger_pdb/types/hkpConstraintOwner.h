// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintOwner; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpConstraintInfo_4a440ac5.h"
struct hkpConstraintOwner__VFTable;
struct hkpConstraintOwner {
    hkpConstraintOwner__VFTable* vftable_hkpConstraintOwner_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpConstraintInfo_4a440ac5 m_constraintInfo_10;
};
static_assert(sizeof(hkpConstraintOwner) == 32, "hkpConstraintOwner layout differs from the PDB");
