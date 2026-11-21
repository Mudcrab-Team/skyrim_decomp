// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCollisionObject; size 0x28
#pragma once

#include "bhkNiCollisionObject.h"
struct bhkCollisionObject {
    bhkNiCollisionObject _base;
};
static_assert(sizeof(bhkCollisionObject) == 40, "bhkCollisionObject layout differs from the PDB");
