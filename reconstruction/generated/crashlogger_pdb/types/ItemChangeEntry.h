// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ItemChangeEntry; size 0x20
#pragma once

#include "CategoryListEntry.h"
struct InventoryEntryData_beab07a8;
struct ItemChangeEntry {
    CategoryListEntry _base;
    InventoryEntryData_beab07a8* data;
};
static_assert(sizeof(ItemChangeEntry) == 32, "ItemChangeEntry layout differs from the PDB");
