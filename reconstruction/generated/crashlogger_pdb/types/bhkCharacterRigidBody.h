// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkCharacterRigidBody; size 0x270
#pragma once

#include "bhkCharacterPointCollector.h"
#include "bhkSerializable_cf25f762.h"
struct NiAVObject;
struct bhkRigidBody;
struct bhkCharacterRigidBody {
    bhkSerializable_cf25f762 _base;
    bhkRigidBody* rigidBody;
    NiAVObject* unk28;
    bhkCharacterPointCollector ignoredCollisionStartCollector;
};
static_assert(sizeof(bhkCharacterRigidBody) == 624, "bhkCharacterRigidBody layout differs from the PDB");
