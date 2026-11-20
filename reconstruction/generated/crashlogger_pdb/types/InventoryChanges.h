// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InventoryChanges; size 0x20
#pragma once

struct BSSimpleList_RE__InventoryEntryData_3a9cfba1;
struct TESObjectREFR_b225f218;
struct InventoryChanges {
    BSSimpleList_RE__InventoryEntryData_3a9cfba1* entryList;
    TESObjectREFR_b225f218* owner;
    float totalWeight;
    float armorWeight;
    bool changed;
    unsigned char unk19;
    unsigned char unk1A;
    unsigned char unk1B;
    unsigned int unk1C;
};
static_assert(sizeof(InventoryChanges) == 32, "InventoryChanges layout differs from the PDB");
