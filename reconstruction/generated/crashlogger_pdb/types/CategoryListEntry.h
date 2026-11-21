// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CategoryListEntry; size 0x18
#pragma once

#include "BSIntrusiveRefCounted.h"
#include "FilterFlag.h"
struct CategoryListEntry_vtbl;
struct CategoryListEntry {
    CategoryListEntry_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    FilterFlag filterFlag;
    bool selected;
    bool enabled;
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(CategoryListEntry) == 24, "CategoryListEntry layout differs from the PDB");
