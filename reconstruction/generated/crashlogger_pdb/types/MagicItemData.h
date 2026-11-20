// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicItemData; size 0x20
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
struct MagicItemData_vtbl;
struct TESForm;
struct MagicItemData {
    MagicItemData_vtbl* __vftable;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce effectDesc;
    TESForm* baseForm;
};
static_assert(sizeof(MagicItemData) == 32, "MagicItemData layout differs from the PDB");
