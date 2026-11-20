// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiExtraDataList; size 0x10
#pragma once

struct NiExtraData;
struct NiExtraDataList {
    NiExtraData** Data_0;
    unsigned short Count_8;
    unsigned short Capacity_A;
    char _pad_C[4];
};
static_assert(sizeof(NiExtraDataList) == 16, "NiExtraDataList layout differs from the PDB");
