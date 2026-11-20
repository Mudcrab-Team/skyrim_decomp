// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSCollisionLayer; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSTArray_RE__BGSCollisionLayer_635c19d9.h"
#include "Color_aa361e09.h"
#include "FLAG_92fc0a0b.h"
#include "TESDescription.h"
#include "TESForm.h"
struct BGSCollisionLayer_8b891558 {
    TESForm _base;
    TESDescription _base_TESDescription;
    unsigned int collisionIdx;
    Color_aa361e09 debugColor;
    FLAG_92fc0a0b flags;
    unsigned int pad3C;
    BSFixedString_char_83b572b4 name;
    BSTArray_RE__BGSCollisionLayer_635c19d9 collidesWith;
};
static_assert(sizeof(BGSCollisionLayer_8b891558) == 96, "BGSCollisionLayer_8b891558 layout differs from the PDB");
