// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpEntityActivationListener *>; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkpEntityActivationListener_093a716f;
struct hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4 {
    hkpEntityActivationListener_093a716f** data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4) == 16, "hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4 layout differs from the PDB");
