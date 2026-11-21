// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionList; size 0x20
#pragma once

#include "BSSimpleList_RE__TESRegion_6a74d605.h"
struct TESRegionList_vtbl;
struct TESRegionList {
    TESRegionList_vtbl* __vftable;
    BSSimpleList_RE__TESRegion_6a74d605 _base_BSSimpleList_RE_TESRegion__;
    bool ownsRegionMemory;
    unsigned char pad19;
    unsigned short pad1A;
    unsigned int pad1C;
};
static_assert(sizeof(TESRegionList) == 32, "TESRegionList layout differs from the PDB");
