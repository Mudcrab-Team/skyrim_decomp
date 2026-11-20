// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpace__DOFData; size 0x10
#pragma once
struct TESImageSpace__DOFData {
    float Strength_0;
    float Distance_4;
    float Range_8;
    char _pad_C[2];
    unsigned short SkyBlurRadius_E;  // SkyBlurRadius in the PDB is wider than this slot
};
static_assert(sizeof(TESImageSpace__DOFData) == 16, "TESImageSpace__DOFData layout differs from the PDB");
