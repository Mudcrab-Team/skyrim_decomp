// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Sun; size 0x58
#pragma once

#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__BSTriShape_e1b1b3c6.h"
#include "NiPointer_RE__NiBillboardNode_acd9a360.h"
#include "NiPointer_RE__NiDirectionalLight_fe8d69e2.h"
#include "SkyObject.h"
struct Sun {
    SkyObject _base;
    NiPointer_RE__NiBillboardNode_acd9a360 sunBaseNode;
    NiPointer_RE__NiBillboardNode_acd9a360 sunGlareNode;
    NiPointer_RE__BSTriShape_e1b1b3c6 sunBase;
    NiPointer_RE__BSTriShape_e1b1b3c6 sunQuery;
    NiPointer_RE__BSTriShape_e1b1b3c6 sunGlare;
    NiPointer_RE__NiDirectionalLight_fe8d69e2 light;
    NiPointer_RE__NiDirectionalLight_fe8d69e2 cloudLight;
    float glareScale;
    bool doOcclusionTests;
    unsigned char pad4D;
    unsigned short pad4E;
    NiPointer_RE__BSShaderAccumulator_c0b65593 sunAccumulator;
};
static_assert(sizeof(Sun) == 88, "Sun layout differs from the PDB");
