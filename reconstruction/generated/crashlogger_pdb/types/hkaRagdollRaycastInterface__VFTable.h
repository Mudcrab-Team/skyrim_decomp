// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkaRagdollRaycastInterface__VFTable; size 0x10
#pragma once

struct hkBool;
struct hkaRagdollRaycastInterface;
struct hkpAabbPhantom;
struct hkaRagdollRaycastInterface__VFTable {
    void (*dtor_0)(hkaRagdollRaycastInterface* );
    hkBool (*castRay_8)(hkaRagdollRaycastInterface* , hkpAabbPhantom* , void*, void*, void*, void*);
};
static_assert(sizeof(hkaRagdollRaycastInterface__VFTable) == 16, "hkaRagdollRaycastInterface__VFTable layout differs from the PDB");
