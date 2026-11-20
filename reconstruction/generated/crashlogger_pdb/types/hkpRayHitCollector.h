// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpRayHitCollector; size 0x10
#pragma once

struct hkpRayHitCollector_vtbl;
struct hkpRayHitCollector {
    hkpRayHitCollector_vtbl* __vftable;
    float earlyOutHitFraction;
    unsigned int pad0C;
};
static_assert(sizeof(hkpRayHitCollector) == 16, "hkpRayHitCollector layout differs from the PDB");
