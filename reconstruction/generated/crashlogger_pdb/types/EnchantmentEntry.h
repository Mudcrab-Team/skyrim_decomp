// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EnchantmentEntry; size 0x28
#pragma once

#include "CategoryListEntry.h"
struct EnchantmentItem_57a0edce;
struct EnchantmentEntry {
    CategoryListEntry _base;
    EnchantmentItem_57a0edce* data;
    float magnitude;
    float maxMagnitude;
};
static_assert(sizeof(EnchantmentEntry) == 40, "EnchantmentEntry layout differs from the PDB");
