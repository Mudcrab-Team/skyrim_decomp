// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESRegionDataManager_vtbl; size 0x50
#pragma once

#include "REGION_DATA_ID.h"
struct TESRegionDataManager_vtbl {
    void (*_dtor_TESRegionDataManager)(void);
    char32_t*(*GetLastLoadedRegion)(void);
    char32_t*(*ConstructRegionData)(REGION_DATA_ID);
    char32_t*(*AsRegionDataObjects)(char32_t* );
    char32_t*(*AsRegionDataWeather)(char32_t* );
    char32_t*(*AsRegionDataMap)(char32_t* );
    char32_t*(*AsRegionDataLandscape)(char32_t* );
    char32_t*(*AsRegionDataGrass)(char32_t* );
    char32_t*(*AsRegionDataSound)(char32_t* );
    bool (*LoadRegionData)(char32_t* , char32_t* );
};
static_assert(sizeof(TESRegionDataManager_vtbl) == 80, "TESRegionDataManager_vtbl layout differs from the PDB");
