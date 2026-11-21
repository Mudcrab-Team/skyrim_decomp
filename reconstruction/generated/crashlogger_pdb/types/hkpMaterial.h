// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpMaterial; size 0xc
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkHalf_603d3829.h"
struct hkpMaterial {
    unsigned char responseType;  // ResponseType in the PDB is wider than this slot
    unsigned char pad01;
    hkHalf_603d3829 rollingFrictionMultiplier;
    float friction;
    float restitution;
};
static_assert(sizeof(hkpMaterial) == 12, "hkpMaterial layout differs from the PDB");
