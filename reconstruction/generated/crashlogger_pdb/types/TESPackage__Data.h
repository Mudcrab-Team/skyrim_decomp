// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__Data; size 0xc
#pragma once
struct TESPackage__Data {
    unsigned int PackageFlags_0;
    char PackageType_4;
    char InterruptOverrideType_5;
    char MaxSpeed_6;
    char _pad_7;
    unsigned short FoBehaviorFlags_8;
    unsigned short PackageSpecificFlags_A;
};
static_assert(sizeof(TESPackage__Data) == 12, "TESPackage__Data layout differs from the PDB");
