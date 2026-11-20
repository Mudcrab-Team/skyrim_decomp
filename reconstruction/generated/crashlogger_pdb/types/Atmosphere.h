// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Atmosphere; size 0x38
#pragma once

#include "NiPointer_RE__BSFogProperty_f30798de.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "SkyObject.h"
struct Atmosphere {
    SkyObject _base;
    NiPointer_RE__BSTriShape_e1b1b3c6 atmosphere;
    NiPointer_RE__BSFogProperty_f30798de fog;
    NiPointer_RE__NiNode_28171d5b skyQuadNode;
    NiPointer_RE__BSTriShape_e1b1b3c6 skyQuad;
    bool updateFogDistance;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(Atmosphere) == 56, "Atmosphere layout differs from the PDB");
