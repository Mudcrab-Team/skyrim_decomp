// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkTransform; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "hkRotation_37435782.h"
#include "hkVector4.h"
struct hkTransform_d380b604 {
    hkRotation_37435782 rotation;
    hkVector4 translation;
};
static_assert(sizeof(hkTransform_d380b604) == 64, "hkTransform_d380b604 layout differs from the PDB");
