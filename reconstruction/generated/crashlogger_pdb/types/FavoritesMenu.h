// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FavoritesMenu; size 0x78
#pragma once

#include "BSTArray_RE__FavoritesMenu__Entry_6eb73a16.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
#include "MenuEventHandler.h"
struct FavoritesMenu {
    IMenu_09c1ffe2 _base;
    MenuEventHandler _base_MenuEventHandler;
    GFxValue root;
    BSTArray_RE__FavoritesMenu__Entry_6eb73a16 favorites;
    unsigned short unk70;
    bool pcControlsReady;
    bool isVampire;
    unsigned int pad74;
};
static_assert(sizeof(FavoritesMenu) == 120, "FavoritesMenu layout differs from the PDB");
