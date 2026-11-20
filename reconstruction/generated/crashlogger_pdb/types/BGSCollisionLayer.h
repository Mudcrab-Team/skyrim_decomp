// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSCollisionLayer; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSCollisionLayer_635c19d9_cdf17a0b.h"
#include "Color.h"
#include "FLAG.h"
#include "TESDescription_99869432.h"
#include "TESForm_4074aa87.h"
struct BGSCollisionLayer {
    TESForm_4074aa87 _base;
    TESDescription_99869432 _base_TESDescription;
    unsigned int collisionIdx;
    Color debugColor;
    FLAG flags;
    unsigned int pad3C;
    unsigned char name_raw[8];
    BSTArray_RE__BGSCollisionLayer_635c19d9_cdf17a0b collidesWith;
};
static_assert(sizeof(BGSCollisionLayer) == 96, "BGSCollisionLayer layout differs from the PDB");
