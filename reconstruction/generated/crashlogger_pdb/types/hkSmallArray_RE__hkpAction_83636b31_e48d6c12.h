// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpAction *>; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct hkpAction_085cde55;
struct hkSmallArray_RE__hkpAction_83636b31_e48d6c12 {
    hkpAction_085cde55** data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpAction_83636b31_e48d6c12) == 16, "hkSmallArray_RE__hkpAction_83636b31_e48d6c12 layout differs from the PDB");
