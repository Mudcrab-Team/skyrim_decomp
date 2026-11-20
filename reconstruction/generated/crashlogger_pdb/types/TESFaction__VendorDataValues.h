// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFaction__VendorDataValues; size 0xc
#pragma once
struct TESFaction__VendorDataValues {
    unsigned short StartHour_0;
    unsigned short EndHour_2;
    unsigned int LocationRadius_4;
    bool BuysStolen_8;
    bool NotBuySell_9;
    bool BuysNonStolen_A;
    char _pad_B;
};
static_assert(sizeof(TESFaction__VendorDataValues) == 12, "TESFaction__VendorDataValues layout differs from the PDB");
