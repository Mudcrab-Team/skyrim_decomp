// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Aabb32Info; size 0x30
#pragma once

#include "hkVector4.h"
struct Aabb32Info {
    hkVector4 bitOffsetLow;
    hkVector4 bitOffsetHigh;
    hkVector4 bitScale;
};
static_assert(sizeof(Aabb32Info) == 48, "Aabb32Info layout differs from the PDB");
