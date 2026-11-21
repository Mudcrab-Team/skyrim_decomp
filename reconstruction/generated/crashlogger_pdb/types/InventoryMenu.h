// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InventoryMenu; size 0x88
#pragma once

#include "BSTArray_void_9eb8914c.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct BottomBar;
struct ItemCard;
struct ItemList;
struct InventoryMenu {
    IMenu_09c1ffe2 _base;
    GFxValue root;
    ItemList* itemList;
    ItemCard* itemCard;
    BottomBar* bottomBar;
    BSTArray_void_9eb8914c unk60;
    unsigned char unk78;
    unsigned char pad79;
    unsigned short pad7A;
    unsigned int unk7C;
    bool pcControlsReady;
    unsigned char unk81;
    unsigned short pad82;
    unsigned int pad84;
};
static_assert(sizeof(InventoryMenu) == 136, "InventoryMenu layout differs from the PDB");
