// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharRigidBodyController; size 0x5b0
#pragma once

#include "bhkCharacterController_0fa35dd3.h"
#include "bhkCharacterRigidBody.h"
#include "hkpCharacterRigidBodyListener.h"
struct bhkCharRigidBodyController {
    bhkCharacterController_0fa35dd3 _base;
    hkpCharacterRigidBodyListener _base_hkpCharacterRigidBodyListener;
    bhkCharacterRigidBody charRigidBody;
};
static_assert(sizeof(bhkCharRigidBodyController) == 1456, "bhkCharRigidBodyController layout differs from the PDB");
