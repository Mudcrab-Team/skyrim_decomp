// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkbNode; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkStringPtr_33d8e88b.h"
#include "hkbBindable.h"
struct hkbNode {
    hkbBindable _base;
    unsigned long long userData;
    hkStringPtr_33d8e88b name;
    unsigned short id;
    unsigned char cloneState;  // CloneState in the PDB is wider than this slot
    unsigned char pad43;
    unsigned int pad44;
};
static_assert(sizeof(hkbNode) == 72, "hkbNode layout differs from the PDB");
