// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BipedObject; size 0x78
#pragma once

#include "NiPointer_NiAVObject_49461dfa.h"
struct BGSTextureSet_d8b0e61f;
struct TESForm_4074aa87;
struct TESModel;
struct TESObjectARMA;
struct BipedObject {
    TESForm_4074aa87* Item_0;
    TESModel* Part_10;
    BGSTextureSet_d8b0e61f* SkinTexture_18;
    NiPointer_NiAVObject_49461dfa PartClone_20;
    char _pad_28[80];
    TESObjectARMA* Addon_8;
};
static_assert(sizeof(BipedObject) == 120, "BipedObject layout differs from the PDB");
