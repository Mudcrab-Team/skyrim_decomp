// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpContactListener *>; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

struct hkpContactListener;
struct hkSmallArray_RE__hkpContactListener_70bf55a3_3949cf0c {
    hkpContactListener** data;
    unsigned short size;
    unsigned short capacityAndFlags;  // CapacityAndFlags in the PDB is wider than this slot
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpContactListener_70bf55a3_3949cf0c) == 16, "hkSmallArray_RE__hkpContactListener_70bf55a3_3949cf0c layout differs from the PDB");
