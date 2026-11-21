// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DismemberedLimb; size 0x20
#pragma once

#include "BSTArray_RE__TESForm_7f041170.h"
struct DismemberedLimb {
    BSTArray_RE__TESForm_7f041170 objects;
    unsigned char limb_raw;
    bool unk19;
    bool unk1A;
    unsigned char pad1B;
    unsigned int pad1C;
};
static_assert(sizeof(DismemberedLimb) == 32, "DismemberedLimb layout differs from the PDB");
