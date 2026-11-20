// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDismemberedLimbs; size 0x40
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSTArray_RE__DismemberedLimb_988d0130.h"
struct TESForm;
struct ExtraDismemberedLimbs {
    BSExtraData_4ca6af76 _base;
    unsigned short limbs;
    bool eaten;
    unsigned char unk13;
    unsigned int unk14;
    TESForm* deathObject;
    BSTArray_RE__DismemberedLimb_988d0130 dismemberedLimbs;
    unsigned char lastHitLimb_raw[4];
    unsigned int pad3C;
};
static_assert(sizeof(ExtraDismemberedLimbs) == 64, "ExtraDismemberedLimbs layout differs from the PDB");
