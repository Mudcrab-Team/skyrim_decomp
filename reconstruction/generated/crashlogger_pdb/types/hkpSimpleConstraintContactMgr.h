// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSimpleConstraintContactMgr; size 0xf0
#pragma once

#include "hkpConstraintInstance.h"
#include "hkpSimpleContactConstraintData.h"
struct hkReferencedObject__VFTable;
struct hkpSimpleConstraintContactMgr__VFTable;
struct hkpWorld_938ebb10;
struct hkpSimpleConstraintContactMgr {
    hkpSimpleConstraintContactMgr__VFTable* vftable_hkpSimpleConstraintContactMgr_0;
    hkReferencedObject__VFTable* vftable_hkReferencedObject_8;
    unsigned short m_memSizeAndFlags_10;
    short m_referenceCount_12;
    char _pad_14[4];
    int m_type_18;
    char _pad_1C[4];
    hkpWorld_938ebb10* m_world_20;
    hkpSimpleContactConstraintData m_contactConstraintData_28;
    hkpConstraintInstance m_constraint_78;
    unsigned int m_pad_E8[1];
    char _pad_EC[4];
};
static_assert(sizeof(hkpSimpleConstraintContactMgr) == 240, "hkpSimpleConstraintContactMgr layout differs from the PDB");
