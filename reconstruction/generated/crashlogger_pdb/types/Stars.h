// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Stars; size 0x20
#pragma once

#include "NiPointer_RE__NiNode_28171d5b.h"
#include "SkyObject.h"
struct Stars {
    SkyObject _base;
    NiPointer_RE__NiNode_28171d5b stars;
    float alpha;
    unsigned int pad1C;
};
static_assert(sizeof(Stars) == 32, "Stars layout differs from the PDB");
