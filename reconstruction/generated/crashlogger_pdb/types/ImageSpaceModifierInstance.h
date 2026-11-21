// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceModifierInstance; size 0x28
#pragma once

#include "NiObject_de5bc370.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
struct ImageSpaceModifierInstance {
    NiObject_de5bc370 _base;
    unsigned int unk10;
    float strength;
    NiPointer_RE__NiAVObject_9e3aa701 target;
    float age;
    unsigned int flags;
};
static_assert(sizeof(ImageSpaceModifierInstance) == 40, "ImageSpaceModifierInstance layout differs from the PDB");
