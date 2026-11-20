// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaRagdollInstance; size 0x48
#pragma once

#include "RE__hkRefPtr_RE__hkaSkeleton_ed84e169.h"
#include "hkArray_RE__hkpConstraintInstance_8fa29619.h"
#include "hkArray_RE__hkpRigidBody_e7cd9bbe.h"
#include "hkArray_int_16774380.h"
#include "hkReferencedObject.h"
struct hkaRagdollInstance {
    hkReferencedObject _base;
    hkArray_RE__hkpRigidBody_e7cd9bbe rigidBodies;
    hkArray_RE__hkpConstraintInstance_8fa29619 constraints;
    hkArray_int_16774380 boneToRigidBodyMap;
    RE__hkRefPtr_RE__hkaSkeleton_ed84e169 skeleton;
};
static_assert(sizeof(hkaRagdollInstance) == 72, "hkaRagdollInstance layout differs from the PDB");
