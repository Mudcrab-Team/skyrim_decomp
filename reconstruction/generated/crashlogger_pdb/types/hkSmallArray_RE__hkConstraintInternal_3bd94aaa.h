// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkConstraintInternal>; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct hkConstraintInternal;
struct hkSmallArray_RE__hkConstraintInternal_3bd94aaa {
    hkConstraintInternal* data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkConstraintInternal_3bd94aaa) == 16, "hkSmallArray_RE__hkConstraintInternal_3bd94aaa layout differs from the PDB");
