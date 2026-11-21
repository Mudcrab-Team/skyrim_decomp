// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ItemList; size 0x58
#pragma once

#include "BSTArray_RE__ItemList__Item_b0d4e7c3.h"
#include "GFxValue.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
struct ItemList {
    GPtr_RE__GFxMovieView_2d8822bd view;
    GFxValue root;
    GFxValue entryList;
    BSTArray_RE__ItemList__Item_b0d4e7c3 items;
    bool unk50;
    unsigned char pad51;
    unsigned short pad52;
    unsigned int pad54;
};
static_assert(sizeof(ItemList) == 88, "ItemList layout differs from the PDB");
