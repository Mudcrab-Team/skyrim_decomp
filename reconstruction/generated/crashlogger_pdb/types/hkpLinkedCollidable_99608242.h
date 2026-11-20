// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLinkedCollidable; size 0x80
// one of 2 different PDB types sharing this name
#pragma once

#include "hkArray_RE__hkpLinkedCollidable__CollisionEntry_fa2aa4cf.h"
#include "hkpCollidable_9bd4f602.h"
struct hkpLinkedCollidable_99608242 {
    hkpCollidable_9bd4f602 _base;
    hkArray_RE__hkpLinkedCollidable__CollisionEntry_fa2aa4cf collisionEntries;
};
static_assert(sizeof(hkpLinkedCollidable_99608242) == 128, "hkpLinkedCollidable_99608242 layout differs from the PDB");
