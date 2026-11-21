// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpConstraintListener *>; size 0x10
#pragma once

struct hkpConstraintListener_8d5d52b3;
struct hkSmallArray_RE__hkpConstraintListener_c6c39a2d {
    hkpConstraintListener_8d5d52b3** data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpConstraintListener_c6c39a2d) == 16, "hkSmallArray_RE__hkpConstraintListener_c6c39a2d layout differs from the PDB");
