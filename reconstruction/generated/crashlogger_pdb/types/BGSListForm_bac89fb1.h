// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSListForm; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__TESForm_7f041170_964e9a4e.h"
#include "TESForm_4074aa87.h"
struct BSTArray_unsigned_int_4b643186_a626a7e9;
struct BGSListForm_bac89fb1 {
    TESForm_4074aa87 _base;
    BSTArray_RE__TESForm_7f041170_964e9a4e forms;
    BSTArray_unsigned_int_4b643186_a626a7e9* scriptAddedTempForms;
    unsigned int scriptAddedFormCount;
    unsigned int pad44;
};
static_assert(sizeof(BGSListForm_bac89fb1) == 72, "BGSListForm_bac89fb1 layout differs from the PDB");
