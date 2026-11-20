// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkSPCollisionObject; size 0x28
#pragma once

#include "bhkPCollisionObject.h"
struct bhkSPCollisionObject {
    bhkPCollisionObject _base;
};
static_assert(sizeof(bhkSPCollisionObject) == 40, "bhkSPCollisionObject layout differs from the PDB");
