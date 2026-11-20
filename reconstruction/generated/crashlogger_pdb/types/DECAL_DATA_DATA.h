// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DECAL_DATA_DATA; size 0x24
#pragma once

#include "Color_aa361e09.h"
struct DECAL_DATA_DATA {
    float decalMinWidth;
    float decalMaxWidth;
    float decalMinHeight;
    float decalMaxHeight;
    float depth;
    float shininess;
    float parallaxScale;
    unsigned char parallaxPasses;
    unsigned char flags_raw;
    unsigned short pad1E;
    Color_aa361e09 color;
};
static_assert(sizeof(DECAL_DATA_DATA) == 36, "DECAL_DATA_DATA layout differs from the PDB");
