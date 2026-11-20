// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAssociationType; size 0x48
#pragma once

#include "FLAGS.h"
#include "TESForm.h"
struct BGSAssociationType {
    TESForm _base;
    unsigned char associationLabels_raw[32];
    FLAGS flags;
    unsigned int pad44;
};
static_assert(sizeof(BGSAssociationType) == 72, "BGSAssociationType layout differs from the PDB");
