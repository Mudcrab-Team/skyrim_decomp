// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImageSpaceModifierInstanceDOF; size 0x78
#pragma once

#include "ImageSpaceModifierInstanceDOF__Data.h"
#include "NiPointer_NiAVObject_49461dfa.h"
struct ImageSpaceModifierInstanceDOF__VFTable;
struct ImageSpaceModifierInstanceDOF {
    ImageSpaceModifierInstanceDOF__VFTable* vftable_ImageSpaceModifierInstanceDOF_0;
    char _pad_8[12];
    float Strength_14;
    NiPointer_NiAVObject_49461dfa Target_18;
    float Age_20;
    unsigned int ModifierInstanceFlags_24;
    float Duration_28;
    char _pad_2C[4];
    ImageSpaceModifierInstanceDOF__Data DOFData_30;
};
static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 120, "ImageSpaceModifierInstanceDOF layout differs from the PDB");
