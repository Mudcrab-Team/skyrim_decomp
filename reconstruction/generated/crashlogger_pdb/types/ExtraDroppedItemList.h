// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraDroppedItemList; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3.h"
struct ExtraDroppedItemList {
    BSExtraData_4ca6af76 _base;
    BSSimpleList_RE__BSPointerHandle_RE__TESObjectREFR_7d43ae12_8c679da3 droppedItemList;
};
static_assert(sizeof(ExtraDroppedItemList) == 32, "ExtraDroppedItemList layout differs from the PDB");
