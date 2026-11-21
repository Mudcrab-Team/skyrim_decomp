// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadFormData; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "Flags_fa7f7281.h"
struct TESForm;
struct BGSLoadFormData_51aca0f8 {
    unsigned int formID;
    unsigned int size;
    unsigned int uncompressedSize;
    unsigned int pad0C;
    TESForm* form;
    unsigned int changeFlags;
    unsigned int oldChangeFlags;
    Flags_fa7f7281 flags;
    unsigned char pad22;
    unsigned char version;
    unsigned char undefined_26[2];
};
static_assert(sizeof(BGSLoadFormData_51aca0f8) == 40, "BGSLoadFormData_51aca0f8 layout differs from the PDB");
