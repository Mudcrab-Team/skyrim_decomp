// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkSmallArray<RE::hkpEntityActivationListener *>; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__hkSmallArray_RE__hkpEntityActivationListener___CapacityAndFlags_unsigned_sh_58bfd6f2.h"
struct hkpEntityActivationListener;
struct hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4_c7370492 {
    hkpEntityActivationListener** data;
    unsigned short size;
    EnumSet_RE__hkSmallArray_RE__hkpEntityActivationListener___CapacityAndFlags_unsigned_sh_58bfd6f2 capacityAndFlags;
    unsigned int pad0C;
};
static_assert(sizeof(hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4_c7370492) == 16, "hkSmallArray_RE__hkpEntityActivationListener_e9a79ad4_c7370492 layout differs from the PDB");
