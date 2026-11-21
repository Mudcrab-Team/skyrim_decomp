// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayCollidableFilter__VFTable; size 0x10
#pragma once

struct hkBool;
struct hkpCollidable;
struct hkpRayCollidableFilter;
struct hkpWorldRayCastInput_439301c5;
struct hkpRayCollidableFilter__VFTable {
    void (*dtor_0)(hkpRayCollidableFilter* );
    hkBool (*isCollisionEnabled_8)(hkpRayCollidableFilter* , hkpWorldRayCastInput_439301c5* , hkpCollidable* );
};
static_assert(sizeof(hkpRayCollidableFilter__VFTable) == 16, "hkpRayCollidableFilter__VFTable layout differs from the PDB");
