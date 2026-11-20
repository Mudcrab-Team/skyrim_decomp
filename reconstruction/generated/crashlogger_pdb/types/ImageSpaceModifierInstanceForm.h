// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceModifierInstanceForm; size 0x50
#pragma once

#include "ImageSpaceModifierInstance.h"
struct TESImageSpaceModifier;
struct ImageSpaceModifierInstanceForm {
    ImageSpaceModifierInstance _base;
    TESImageSpaceModifier* imod;
    unsigned long long unk30;
    float unk38;
    unsigned int unk3C;
    unsigned long long unk40;
    unsigned int unk48;
    unsigned char undefined_4c[4];
};
static_assert(sizeof(ImageSpaceModifierInstanceForm) == 80, "ImageSpaceModifierInstanceForm layout differs from the PDB");
