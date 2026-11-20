// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ItemCard; size 0x40
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "GFxValue.h"
#include "GPtr_RE__GFxMovieView_2d8822bd.h"
struct ItemCard {
    GFxValue obj;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce infoText;
    void* unk28;
    unsigned int unk30;
    unsigned int pad34;
    GPtr_RE__GFxMovieView_2d8822bd view;
};
static_assert(sizeof(ItemCard) == 64, "ItemCard layout differs from the PDB");
