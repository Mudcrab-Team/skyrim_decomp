// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FACTION_VENDOR_DATA; size 0x38
#pragma once

#include "FACTION_VENDOR_DATA_VALUES.h"
struct BGSListForm;
struct PackageLocation;
struct TESCondition_4d3cdc88;
struct TESObjectREFR_b225f218;
struct FACTION_VENDOR_DATA {
    FACTION_VENDOR_DATA_VALUES vendorValues;
    unsigned int pad0C;
    PackageLocation* vendorLocation;
    TESCondition_4d3cdc88* vendorConditions;
    BGSListForm* vendorSellBuyList;
    TESObjectREFR_b225f218* merchantContainer;
    unsigned int lastDayReset;
    unsigned int pad34;
};
static_assert(sizeof(FACTION_VENDOR_DATA) == 56, "FACTION_VENDOR_DATA layout differs from the PDB");
