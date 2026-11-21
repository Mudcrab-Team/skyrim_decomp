// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkRigidBodyT; size 0x60
#pragma once

#include "bhkRigidBody.h"
#include "hkQuaternion_eff9c81f.h"
#include "hkVector4.h"
struct bhkRigidBodyT {
    bhkRigidBody _base;
    hkQuaternion_eff9c81f rotation;
    hkVector4 translation;
};
static_assert(sizeof(bhkRigidBodyT) == 96, "bhkRigidBodyT layout differs from the PDB");
