// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction__VendorData; size 0x38
#pragma once

#include "TESFaction__VendorDataValues.h"
struct BGSListForm_bac89fb1;
struct PackageLocation_8e1e4e82;
struct TESCondition;
struct TESObjectREFR;
struct TESFaction__VendorData {
    TESFaction__VendorDataValues VendorValues_0;
    char _pad_C[4];
    PackageLocation_8e1e4e82* VendorLocation_10;
    TESCondition* VendorConditions_18;
    BGSListForm_bac89fb1* VendorSellBuyList_20;
    TESObjectREFR* MerchantContainer_28;
    int LastDayReset_30;
    char _pad_34[4];
};
static_assert(sizeof(TESFaction__VendorData) == 56, "TESFaction__VendorData layout differs from the PDB");
