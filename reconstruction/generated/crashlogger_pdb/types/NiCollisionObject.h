// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCollisionObject; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiObject.h"
struct NiAVObject_968dc716;
struct NiCollisionObject__VFTable;
struct NiCollisionObject {
    NiObject _base;
    NiAVObject_968dc716* OwnerObject_10;
    NiCollisionObject__VFTable* vftable_NiCollisionObject_0;
};
static_assert(sizeof(NiCollisionObject) == 32, "NiCollisionObject layout differs from the PDB");
