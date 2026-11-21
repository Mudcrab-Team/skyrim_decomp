// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBroadPhaseListener__VFTable; size 0x18
#pragma once

struct hkpBroadPhaseListener;
struct hkpTypedBroadPhaseHandlePair;
struct hkpBroadPhaseListener__VFTable {
    void (*dtor_0)(hkpBroadPhaseListener* );
    void (*addCollisionPair_8)(hkpBroadPhaseListener* , hkpTypedBroadPhaseHandlePair* );
    void (*removeCollisionPair_10)(hkpBroadPhaseListener* , hkpTypedBroadPhaseHandlePair* );
};
static_assert(sizeof(hkpBroadPhaseListener__VFTable) == 24, "hkpBroadPhaseListener__VFTable layout differs from the PDB");
