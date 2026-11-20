// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpPhantomOverlapListener__VFTable; size 0x18
#pragma once

struct hkpCollidableAddedEvent;
struct hkpCollidableRemovedEvent;
struct hkpPhantomOverlapListener;
struct hkpPhantomOverlapListener__VFTable {
    void (*collidableAddedCallback_0)(hkpPhantomOverlapListener* , hkpCollidableAddedEvent* );
    void (*collidableRemovedCallback_8)(hkpPhantomOverlapListener* , hkpCollidableRemovedEvent* );
    void (*dtor_10)(hkpPhantomOverlapListener* );
};
static_assert(sizeof(hkpPhantomOverlapListener__VFTable) == 24, "hkpPhantomOverlapListener__VFTable layout differs from the PDB");
