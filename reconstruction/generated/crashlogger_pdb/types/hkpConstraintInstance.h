// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintInstance; size 0x70
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkBool.h"
#include "hkEnum_hkpConstraintInstance__ConstraintPriority_uint8.h"
#include "hkEnum_hkpConstraintInstance__OnDestructionRemapInfo_uint8.h"
#include "hkSmallArray_hkpConstraintListener_74623d4e.h"
#include "hkStringPtr.h"
struct hkConstraintInternal_4023762f;
struct hkpConstraintData;
struct hkpConstraintInstance__VFTable;
struct hkpConstraintOwner;
struct hkpEntity_b3bc9432;
struct hkpModifierConstraintAtom;
struct hkpConstraintInstance {
    hkpConstraintInstance__VFTable* vftable_hkpConstraintInstance_0;
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_C[4];
    hkpConstraintOwner* m_owner_10;
    hkpConstraintData* m_data_18;
    hkpModifierConstraintAtom* m_constraintModifiers_20;
    hkpEntity_b3bc9432* m_entities_28[2];
    hkEnum_hkpConstraintInstance__ConstraintPriority_uint8 m_priority_38;
    hkBool m_wantRuntime_39;
    hkEnum_hkpConstraintInstance__OnDestructionRemapInfo_uint8 m_destructionRemapInfo_3A;
    char _pad_3B[5];
    hkSmallArray_hkpConstraintListener_74623d4e m_listeners_40;
    hkStringPtr m_name_50;
    unsigned long long m_userData_58;
    hkConstraintInternal_4023762f* m_internal_60;
    unsigned int m_uid_68;
    char _pad_6C[4];
};
static_assert(sizeof(hkpConstraintInstance) == 112, "hkpConstraintInstance layout differs from the PDB");
