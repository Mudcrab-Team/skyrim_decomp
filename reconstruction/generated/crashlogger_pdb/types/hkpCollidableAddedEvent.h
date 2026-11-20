// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidableAddedEvent; size 0x18
#pragma once

struct hkpCollidable;
struct hkpPhantom;
struct hkpCollidableAddedEvent {
    hkpPhantom* m_phantom_0;
    hkpCollidable* m_collidable_8;
    int m_collidableAccept_10;
    char _pad_14[4];
};
static_assert(sizeof(hkpCollidableAddedEvent) == 24, "hkpCollidableAddedEvent layout differs from the PDB");
