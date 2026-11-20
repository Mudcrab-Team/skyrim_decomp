// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSOutfit; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__TESForm_7f041170.h"
#include "TESForm.h"
struct BGSOutfit {
    TESForm _base;
    BSTArray_RE__TESForm_7f041170 outfitItems;
};
static_assert(sizeof(BGSOutfit) == 56, "BGSOutfit layout differs from the PDB");
