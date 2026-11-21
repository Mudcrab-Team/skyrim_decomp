// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkNiCollisionObject; size 0x28
#pragma once

#include "Flag_a4a94b8a.h"
#include "NiCollisionObject_c8e738ef.h"
#include "NiPointer_RE__bhkWorldObject_64036967.h"
struct bhkNiCollisionObject {
    NiCollisionObject_c8e738ef _base;
    Flag_a4a94b8a flags;
    unsigned int pad1C;
    NiPointer_RE__bhkWorldObject_64036967 body;
};
static_assert(sizeof(bhkNiCollisionObject) == 40, "bhkNiCollisionObject layout differs from the PDB");
