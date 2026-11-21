// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDecalNode; size 0x148
#pragma once

#include "BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d.h"
#include "NiNode.h"
struct BGSDecalNode {
    NiNode _base;
    BSTArray_RE__NiPointer_RE__BSTempEffect_c3f9787d decals;
    bool isSkinned;
    unsigned char undefined_141[7];
};
static_assert(sizeof(BGSDecalNode) == 328, "BGSDecalNode layout differs from the PDB");
