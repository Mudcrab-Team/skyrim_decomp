// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpBvTreeShape; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "hkpShape_890c4847.h"
struct hkpBvTreeShape_f0c78d2e {
    hkpShape_890c4847 _base;
    unsigned char bvTreeType;  // BvTreeType in the PDB is wider than this slot
    unsigned char pad21;
    unsigned short pad22;
    unsigned int pad24;
};
static_assert(sizeof(hkpBvTreeShape_f0c78d2e) == 40, "hkpBvTreeShape_f0c78d2e layout differs from the PDB");
