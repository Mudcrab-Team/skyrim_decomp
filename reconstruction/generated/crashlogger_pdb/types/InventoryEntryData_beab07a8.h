// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InventoryEntryData; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

struct BSSimpleList_RE__ExtraDataList_67ca60e5;
struct TESBoundObject_fc790793;
struct InventoryEntryData_beab07a8 {
    TESBoundObject_fc790793* object;
    BSSimpleList_RE__ExtraDataList_67ca60e5* extraLists;
    int countDelta;
    unsigned int pad14;
};
static_assert(sizeof(InventoryEntryData_beab07a8) == 24, "InventoryEntryData_beab07a8 layout differs from the PDB");
