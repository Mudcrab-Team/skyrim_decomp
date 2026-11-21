// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSReferenceEffect; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESForm.h"
struct BGSReferenceEffect {
    TESForm _base;
    unsigned char data_raw[24];
};
static_assert(sizeof(BGSReferenceEffect) == 56, "BGSReferenceEffect layout differs from the PDB");
