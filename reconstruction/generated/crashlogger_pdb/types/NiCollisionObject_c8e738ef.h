// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCollisionObject; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "NiObject_de5bc370.h"
struct NiAVObject;
struct NiCollisionObject_c8e738ef {
    NiObject_de5bc370 _base;
    NiAVObject* sceneObject;
};
static_assert(sizeof(NiCollisionObject_c8e738ef) == 24, "NiCollisionObject_c8e738ef layout differs from the PDB");
