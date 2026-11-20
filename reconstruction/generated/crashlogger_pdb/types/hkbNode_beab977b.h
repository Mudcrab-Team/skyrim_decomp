// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbNode; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__hkbNode__CloneState_unsigned_char_e3102110.h"
#include "hkStringPtr.h"
#include "hkbBindable_7236c8b2.h"
struct hkbNode_beab977b {
    hkbBindable_7236c8b2 _base;
    unsigned long long userData;
    hkStringPtr name;
    unsigned short id;
    EnumSet_RE__hkbNode__CloneState_unsigned_char_e3102110 cloneState;
    unsigned char pad43;
    unsigned int pad44;
};
static_assert(sizeof(hkbNode_beab977b) == 72, "hkbNode_beab977b layout differs from the PDB");
