// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpEntityListener *>; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpEntityListener;
struct hkSmallArray_RE__hkpEntityListener_3222427a {
    hkpEntityListener** data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpEntityListener_3222427a) == 16, "hkSmallArray_RE__hkpEntityListener_3222427a layout differs from the PDB");
