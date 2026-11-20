// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSLoadFormData; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct TESForm_4074aa87;
struct BGSLoadFormData {
    unsigned int formID;
    unsigned int size;
    unsigned int uncompressedSize;
    unsigned int pad0C;
    TESForm_4074aa87* form;
    unsigned int changeFlags;
    unsigned int oldChangeFlags;
    int flags;
    unsigned char pad22;
    unsigned char version;
    unsigned char undefined_26[2];
};
static_assert(sizeof(BGSLoadFormData) == 40, "BGSLoadFormData layout differs from the PDB");
