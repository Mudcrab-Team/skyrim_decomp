// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSValueNode; size 0x138
#pragma once

#include "BSNiNode_57174b0c.h"
#include "NiPointer_RE__BSMasterParticleSystem_20b34ba1.h"
struct BSValueNode {
    BSNiNode_57174b0c _base;
    unsigned char flags;
    unsigned char undefined_129[3];
    unsigned int value;
    NiPointer_RE__BSMasterParticleSystem_20b34ba1 associatedObject;
};
static_assert(sizeof(BSValueNode) == 312, "BSValueNode layout differs from the PDB");
