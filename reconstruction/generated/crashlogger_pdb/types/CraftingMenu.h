// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CraftingMenu; size 0x38
#pragma once

#include "GPtr_FxDelegate_af844bf8.h"
#include "GPtr_GFxMovieView_ed8a74e4.h"
struct CraftingMenu__VFTable;
struct CraftingSubMenus__CraftingSubMenu;
struct CraftingMenu {
    CraftingMenu__VFTable* vftable_CraftingMenu_0;
    int RefCount_8;
    char _pad_C[4];
    GPtr_GFxMovieView_ed8a74e4 View_10;
    unsigned char MenuDepth_18;
    char _pad_19[3];
    unsigned int MenuFlags_1C;
    int Context_20;
    char _pad_24[4];
    GPtr_FxDelegate_af844bf8 Delegate_28;
    CraftingSubMenus__CraftingSubMenu* SubMenu_30;
};
static_assert(sizeof(CraftingMenu) == 56, "CraftingMenu layout differs from the PDB");
