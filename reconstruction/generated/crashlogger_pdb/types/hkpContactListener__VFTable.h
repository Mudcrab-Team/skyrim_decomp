// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpContactListener__VFTable; size 0x38
#pragma once

struct hkpCollisionEvent;
struct hkpContactListener_82acfcff;
struct hkpContactPointAddedEvent;
struct hkpContactPointEvent;
struct hkpContactPointRemovedEvent;
struct hkpContactProcessEvent;
struct hkpContactListener__VFTable {
    void (*contactPointCallback_0)(hkpContactListener_82acfcff* , hkpContactPointEvent* );
    void (*collisionAddedCallback_8)(hkpContactListener_82acfcff* , hkpCollisionEvent* );
    void (*collisionRemovedCallback_10)(hkpContactListener_82acfcff* , hkpCollisionEvent* );
    void (*dtor_18)(hkpContactListener_82acfcff* );
    void (*contactPointAddedCallback_20)(hkpContactListener_82acfcff* , hkpContactPointAddedEvent* );
    void (*contactPointRemovedCallback_28)(hkpContactListener_82acfcff* , hkpContactPointRemovedEvent* );
    void (*contactProcessCallback_30)(hkpContactListener_82acfcff* , hkpContactProcessEvent* );
};
static_assert(sizeof(hkpContactListener__VFTable) == 56, "hkpContactListener__VFTable layout differs from the PDB");
