// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBillboardNode; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiNode.h"
struct NiBillboardNode {
    NiNode _base;
    unsigned short userFlags;
    unsigned char undefined_12a[6];
};
static_assert(sizeof(NiBillboardNode) == 304, "NiBillboardNode layout differs from the PDB");
