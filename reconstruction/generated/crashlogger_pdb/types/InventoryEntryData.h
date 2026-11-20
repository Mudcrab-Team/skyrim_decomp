// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InventoryEntryData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSSimpleList_BSExtraDataList;
struct TESBoundObject;
struct InventoryEntryData {
    TESBoundObject* object_0;
    BSSimpleList_BSExtraDataList* extraLists_8;
    int countDelta_10;
    unsigned int pad_14;
};
static_assert(sizeof(InventoryEntryData) == 24, "InventoryEntryData layout differs from the PDB");
