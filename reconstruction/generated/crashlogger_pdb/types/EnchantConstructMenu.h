// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EnchantConstructMenu; size 0x220
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTArray_RE__BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__CategoryListEn_caad7266.h"
#include "Category_fc48b582.h"
#include "CraftingSubMenu.h"
#include "CreateEffectFunctor.h"
#include "FilterFlag.h"
#include "GFxValue.h"
#include "Selections.h"
struct InventoryEntryData_beab07a8;
struct EnchantConstructMenu {
    CraftingSubMenu _base;
    FilterFlag filters[5];
    unsigned int pad114;
    BSTArray_RE__BSTSmartPointer_RE__CraftingSubMenus__EnchantConstructMenu__CategoryListEn_caad7266 listEntries;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce customName;
    GFxValue categories;
    GFxValue inventoryLists;
    Selections selected;
    InventoryEntryData_beab07a8* craftItemPreview;
    CreateEffectFunctor createEffectFunctor;
    int sliderEnchantmentIndex;
    float sliderMaxMagnitude;
    unsigned int highlightIndex;
    Category_fc48b582 currentCategory;
    FilterFlag enabledFilters;
    float enchantmentCost;
    float chargeAmount;
    bool exiting;
    bool sliderShown;
    bool hasHighlightedEntry;
    unsigned char pad21F;
};
static_assert(sizeof(EnchantConstructMenu) == 544, "EnchantConstructMenu layout differs from the PDB");
