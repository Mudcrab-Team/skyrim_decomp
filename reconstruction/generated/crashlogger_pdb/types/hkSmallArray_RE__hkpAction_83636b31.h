// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpAction *>; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "EnumSet_RE__hkSmallArray_RE__hkpAction___CapacityAndFlags_unsigned_short_6e508a68.h"
struct hkpAction;
struct hkSmallArray_RE__hkpAction_83636b31 {
    hkpAction** data;
    unsigned short size;
    EnumSet_RE__hkSmallArray_RE__hkpAction___CapacityAndFlags_unsigned_short_6e508a68 capacityAndFlags;
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpAction_83636b31) == 16, "hkSmallArray_RE__hkpAction_83636b31 layout differs from the PDB");
