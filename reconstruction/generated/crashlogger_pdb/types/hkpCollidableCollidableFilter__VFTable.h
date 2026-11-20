// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollidableCollidableFilter__VFTable; size 0x10
#pragma once

struct hkBool;
struct hkpCollidable;
struct hkpCollidableCollidableFilter_d1d3e761;
struct hkpCollidableCollidableFilter__VFTable {
    void (*dtor_0)(hkpCollidableCollidableFilter_d1d3e761* );
    hkBool (*isCollisionEnabled_8)(hkpCollidableCollidableFilter_d1d3e761* , hkpCollidable* , hkpCollidable* );
};
static_assert(sizeof(hkpCollidableCollidableFilter__VFTable) == 16, "hkpCollidableCollidableFilter__VFTable layout differs from the PDB");
