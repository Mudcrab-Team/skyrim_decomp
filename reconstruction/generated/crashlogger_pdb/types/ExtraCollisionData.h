// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraCollisionData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct CollisionData;
struct ExtraCollisionData {
    BSExtraData_4ca6af76 _base;
    CollisionData* collisionData;
};
static_assert(sizeof(ExtraCollisionData) == 24, "ExtraCollisionData layout differs from the PDB");
