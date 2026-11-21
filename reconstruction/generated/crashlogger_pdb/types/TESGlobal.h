// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESGlobal; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "TESForm.h"
struct TESGlobal {
    TESForm _base;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
    unsigned char type;  // Type in the PDB is wider than this slot
    unsigned char pad31;
    unsigned short pad32;
    float value;
};
static_assert(sizeof(TESGlobal) == 56, "TESGlobal layout differs from the PDB");
