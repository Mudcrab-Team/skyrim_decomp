// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CraftingSubMenu; size 0x100
#pragma once

#include "BSTEventSink_RE__TESFurnitureEvent_367f773e.h"
#include "FxDelegateHandler_ccd4e5d3.h"
#include "GFxValue.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
struct BottomBar;
struct ItemCard;
struct TESFurniture;
struct CraftingSubMenu {
    FxDelegateHandler_ccd4e5d3 _base;
    BSTEventSink_RE__TESFurnitureEvent_367f773e _base_BSTEventSink_RE_TESFurnitureEvent_;
    GPtr_RE__GFxMovieView_2d8822bd view;
    TESFurniture* furniture;
    ItemCard* itemCard;
    BottomBar* bottomBar;
    GFxValue craftingMenu;
    GFxValue itemList;
    GFxValue entryList;
    GFxValue itemInfo;
    GFxValue bottomBarInfo;
    GFxValue additionalDescription;
    GFxValue menuName;
    GFxValue buttonText;
    bool unk0F8;
    unsigned char pad0F9;
    unsigned short pad0FA;
    unsigned int pad0FC;
};
static_assert(sizeof(CraftingSubMenu) == 256, "CraftingSubMenu layout differs from the PDB");
