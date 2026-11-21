// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataManager; size 0x10
#pragma once

struct TESRegion;
struct TESRegionDataManager_vtbl;
struct TESRegionDataManager {
    TESRegionDataManager_vtbl* __vftable;
    TESRegion* lastLoadedRegion;
};
static_assert(sizeof(TESRegionDataManager) == 16, "TESRegionDataManager layout differs from the PDB");
