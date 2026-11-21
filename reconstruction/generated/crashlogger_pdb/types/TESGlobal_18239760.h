// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESGlobal; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "EnumSet_RE__TESGlobal__Type_unsigned_char_5eddb5c1.h"
#include "TESForm_4074aa87.h"
struct TESGlobal_18239760 {
    TESForm_4074aa87 _base;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce formEditorID;
    EnumSet_RE__TESGlobal__Type_unsigned_char_5eddb5c1 type;
    unsigned char pad31;
    unsigned short pad32;
    float value;
};
static_assert(sizeof(TESGlobal_18239760) == 56, "TESGlobal_18239760 layout differs from the PDB");
