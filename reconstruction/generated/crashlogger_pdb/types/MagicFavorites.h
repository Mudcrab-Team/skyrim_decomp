// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicFavorites; size 0x40
#pragma once

#include "BSTArray_RE__TESForm_7f041170.h"
#include "BSTSingletonSDM_RE__MagicFavorites_8a08b3fd.h"
struct MagicFavorites_vtbl;
struct MagicFavorites {
    MagicFavorites_vtbl* __vftable;
    BSTSingletonSDM_RE__MagicFavorites_8a08b3fd _base_BSTSingletonSDM_RE_MagicFavorites_;
    unsigned char pad09;
    unsigned short pad0A;
    unsigned int pad0C;
    BSTArray_RE__TESForm_7f041170 spells;
    BSTArray_RE__TESForm_7f041170 hotkeys;
};
static_assert(sizeof(MagicFavorites) == 64, "MagicFavorites layout differs from the PDB");
