// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Selections; size 0x30
#pragma once

#include "BSTArray_RE__BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__EnchantmentEnt_b2ba4ea9.h"
#include "BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__ItemChangeEntry_84a93dde.h"
struct Selections {
    BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__ItemChangeEntry_84a93dde item;
    BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__ItemChangeEntry_84a93dde soulGem;
    BSTArray_RE__BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__EnchantmentEnt_b2ba4ea9 effects;
    unsigned int numEnchantmentsAllowed;
    unsigned int pad2C;
};
static_assert(sizeof(Selections) == 48, "Selections layout differs from the PDB");
