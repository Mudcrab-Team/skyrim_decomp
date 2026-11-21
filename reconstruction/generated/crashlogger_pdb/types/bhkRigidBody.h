// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkRigidBody; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_void_9eb8914c.h"
#include "bhkEntity_0195ac54.h"
struct bhkRigidBody {
    bhkEntity_0195ac54 _base;
    BSTArray_void_9eb8914c unk28;
};
static_assert(sizeof(bhkRigidBody) == 64, "bhkRigidBody layout differs from the PDB");
