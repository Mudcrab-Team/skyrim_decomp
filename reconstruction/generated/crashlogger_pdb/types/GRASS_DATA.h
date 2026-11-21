// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GRASS_DATA; size 0x20
#pragma once

#include "EnumSet_RE__TESGrass__GRASS_DATA__Flag_unsigned_char_3c08e06b.h"
#include "EnumSet_RE__TESGrass__GRASS_WATER_STATE_unsigned_int_46e5c88d.h"
struct GRASS_DATA {
    unsigned char density;
    unsigned char minSlopeDegrees;
    unsigned char maxSlopeDegrees;
    unsigned char pad03;
    unsigned short distanceFromWaterLevel;
    unsigned short pad06;
    EnumSet_RE__TESGrass__GRASS_WATER_STATE_unsigned_int_46e5c88d underwater;
    float positionRange;
    float heightRange;
    float colorRange;
    float wavePeriod;
    EnumSet_RE__TESGrass__GRASS_DATA__Flag_unsigned_char_3c08e06b flags;
    unsigned char pad1D;
    unsigned short pad1E;
};
static_assert(sizeof(GRASS_DATA) == 32, "GRASS_DATA layout differs from the PDB");
