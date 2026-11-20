// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintInstance; size 0x70
// one of 2 different PDB types sharing this name
#pragma once

#include "hkReferencedObject.h"
#include "hkSmallArray_RE__hkpConstraintListener_c6c39a2d.h"
#include "hkStringPtr_33d8e88b.h"
struct hkConstraintInternal;
struct hkpConstraintData_7581c038;
struct hkpConstraintOwner_1e63eaed;
struct hkpEntity;
struct hkpModifierConstraintAtom_52b61b44;
struct hkpConstraintInstance_7e571b14 {
    hkReferencedObject _base;
    hkpConstraintOwner_1e63eaed* owner;
    hkpConstraintData_7581c038* data;
    hkpModifierConstraintAtom_52b61b44* constraintModifiers;
    hkpEntity* entities[2];
    unsigned char priority;  // ConstraintPriority in the PDB is wider than this slot
    bool wantRuntime;
    unsigned char destructionRemapInfo_raw[6];
    hkSmallArray_RE__hkpConstraintListener_c6c39a2d listeners;
    hkStringPtr_33d8e88b name;
    unsigned long long userData;
    hkConstraintInternal* internal;
    unsigned int uid;
    unsigned char undefined_6c[4];
};
static_assert(sizeof(hkpConstraintInstance_7e571b14) == 112, "hkpConstraintInstance_7e571b14 layout differs from the PDB");
