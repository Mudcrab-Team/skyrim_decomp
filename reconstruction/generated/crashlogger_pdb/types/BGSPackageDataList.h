// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSPackageDataList; size 0x18
#pragma once

struct IPackageData;
struct BGSPackageDataList {
    IPackageData** data;
    unsigned char* uids;
    unsigned short dataSize;
    unsigned char nextUID;
    unsigned char pad13;
    unsigned int pad14;
};
static_assert(sizeof(BGSPackageDataList) == 24, "BGSPackageDataList layout differs from the PDB");
