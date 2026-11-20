// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSFootstep; size 0x30
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "TESForm.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSFootstep {
    TESForm _base;
    BSFixedString_char_83b572b4 tag;
    BGSImpactDataSet_e1a4fffc* impactSet;
};
static_assert(sizeof(BGSFootstep) == 48, "BGSFootstep layout differs from the PDB");
