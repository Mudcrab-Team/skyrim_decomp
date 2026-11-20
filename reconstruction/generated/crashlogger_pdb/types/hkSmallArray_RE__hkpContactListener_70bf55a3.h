// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpContactListener *>; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__hkSmallArray_RE__hkpContactListener___CapacityAndFlags_unsigned_short_57c01ead.h"
struct hkpContactListener_82acfcff;
struct hkSmallArray_RE__hkpContactListener_70bf55a3 {
    hkpContactListener_82acfcff** data;
    unsigned short size;
    EnumSet_RE__hkSmallArray_RE__hkpContactListener___CapacityAndFlags_unsigned_short_57c01ead capacityAndFlags;
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpContactListener_70bf55a3) == 16, "hkSmallArray_RE__hkpContactListener_70bf55a3 layout differs from the PDB");
