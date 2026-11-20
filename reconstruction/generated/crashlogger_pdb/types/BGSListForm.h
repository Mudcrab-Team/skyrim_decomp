// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSListForm; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__TESForm_7f041170.h"
#include "TESForm.h"
struct BSTArray_unsigned_int_4b643186;
struct BGSListForm {
    TESForm _base;
    BSTArray_RE__TESForm_7f041170 forms;
    BSTArray_unsigned_int_4b643186* scriptAddedTempForms;
    unsigned int scriptAddedFormCount;
    unsigned int pad44;
};
static_assert(sizeof(BGSListForm) == 72, "BGSListForm layout differs from the PDB");
