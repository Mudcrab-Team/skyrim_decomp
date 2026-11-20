// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataList; size 0x18
#pragma once

#include "BSSimpleList_RE__TESRegionData_30ee0ec2.h"
struct TESRegionDataList {
    BSSimpleList_RE__TESRegionData_30ee0ec2 regionDataList;
    bool unk11;
    unsigned char undefined_11[1];
    unsigned short pad12;
    unsigned int pad14;
};
static_assert(sizeof(TESRegionDataList) == 24, "TESRegionDataList layout differs from the PDB");
