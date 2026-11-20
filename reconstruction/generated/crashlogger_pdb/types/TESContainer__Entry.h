// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESContainer__Entry; size 0x18
#pragma once

struct TESContainer__Data;
struct TESForm_4074aa87;
struct TESContainer__Entry {
    int Count_0;
    char _pad_4[4];
    TESForm_4074aa87* Item_8;
    TESContainer__Data* EntryData_10;
};
static_assert(sizeof(TESContainer__Entry) == 24, "TESContainer__Entry layout differs from the PDB");
