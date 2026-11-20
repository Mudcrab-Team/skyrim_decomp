// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSOrderedNode; size 0x140
#pragma once

#include "BSNiNode_57174b0c.h"
#include "NiBound_6900288c.h"
struct BSOrderedNode {
    BSNiNode_57174b0c _base;
    NiBound_6900288c orderedBound;
    bool useStaticBound;
    unsigned char undefined_139[3];
    unsigned int pad13C;
};
static_assert(sizeof(BSOrderedNode) == 320, "BSOrderedNode layout differs from the PDB");
