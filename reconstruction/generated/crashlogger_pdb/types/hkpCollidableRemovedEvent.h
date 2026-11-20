// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidableRemovedEvent; size 0x18
#pragma once

#include "hkBool.h"
struct hkpCollidable;
struct hkpPhantom;
struct hkpCollidableRemovedEvent {
    hkpPhantom* m_phantom_0;
    hkpCollidable* m_collidable_8;
    hkBool m_collidableWasAdded_10;
    char _pad_11[7];
};
static_assert(sizeof(hkpCollidableRemovedEvent) == 24, "hkpCollidableRemovedEvent layout differs from the PDB");
