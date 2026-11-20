// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AttachTechniqueInput; size 0x20
#pragma once

#include "NiPointer_RE__NiNode_28171d5b.h"
struct AttachTechniqueInput_vtbl;
struct AttachTechniqueInput {
    AttachTechniqueInput_vtbl* __vftable;
    NiPointer_RE__NiNode_28171d5b current3DRoot;
    NiPointer_RE__NiNode_28171d5b attachedArt;
    unsigned int attachPoint;
    unsigned int pad18;
};
static_assert(sizeof(AttachTechniqueInput) == 32, "AttachTechniqueInput layout differs from the PDB");
