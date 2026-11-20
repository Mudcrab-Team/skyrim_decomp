// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionData; size 0x10
#pragma once

#include "DataHeader.h"
struct TESRegionData_vtbl;
struct TESRegionData {
    TESRegionData_vtbl* __vftable;
    DataHeader dataHeader;
};
static_assert(sizeof(TESRegionData) == 16, "TESRegionData layout differs from the PDB");
