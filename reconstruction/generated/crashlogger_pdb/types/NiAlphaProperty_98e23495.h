// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAlphaProperty; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "NiProperty_29cbd083.h"
struct NiAlphaProperty_98e23495 {
    NiProperty_29cbd083 _base;
    unsigned short alphaFlags;
    unsigned char alphaThreshold;
    unsigned char pad33;
    unsigned int pad34;
};
static_assert(sizeof(NiAlphaProperty_98e23495) == 56, "NiAlphaProperty_98e23495 layout differs from the PDB");
