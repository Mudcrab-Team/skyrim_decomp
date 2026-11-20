// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkPCollisionObject; size 0x28
#pragma once

#include "bhkNiCollisionObject.h"
struct bhkPCollisionObject {
    bhkNiCollisionObject _base;
};
static_assert(sizeof(bhkPCollisionObject) == 40, "bhkPCollisionObject layout differs from the PDB");
