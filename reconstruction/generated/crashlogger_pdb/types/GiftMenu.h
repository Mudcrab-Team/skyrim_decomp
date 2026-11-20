// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GiftMenu; size 0x80
#pragma once

#include "BSTArray_void_9eb8914c.h"
#include "GFxValue.h"
#include "IMenu_09c1ffe2.h"
struct ItemCard;
struct ItemList;
struct GiftMenu {
    IMenu_09c1ffe2 _base;
    GFxValue root;
    ItemList* itemList;
    ItemCard* itemCard;
    BSTArray_void_9eb8914c unk58;
    int totalValueTransferred;
    unsigned int unk74;
    bool pcControlsReady;
    unsigned char pad79;
    unsigned short pad7A;
    unsigned int pad7C;
};
static_assert(sizeof(GiftMenu) == 128, "GiftMenu layout differs from the PDB");
