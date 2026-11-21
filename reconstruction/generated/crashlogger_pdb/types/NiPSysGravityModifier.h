// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiPSysGravityModifier; size 0x60
#pragma once

#include "ForceType.h"
#include "NiPSysModifier.h"
#include "NiPoint3.h"
struct NiAVObject;
struct NiPSysGravityModifier {
    NiPSysModifier _base;
    NiAVObject* gravityObj;
    NiPoint3 gravityAxis;
    float decay;
    float strength;
    ForceType forceType;
    float turbulence;
    float scale;
    bool worldAligned;
    unsigned char pad59;
    unsigned short pad5A;
    unsigned int pad5C;
};
static_assert(sizeof(NiPSysGravityModifier) == 96, "NiPSysGravityModifier layout differs from the PDB");
