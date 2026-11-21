// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESClimate; size 0x80
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSimpleList_WeatherType_1a03eb11.h"
#include "TESClimate__TimingData.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESModel.h"
#include "TESTexture_fe82fffc.h"
struct TESClimate__VFTable;
struct TESClimate {
    TESClimate__VFTable* vftable_TESClimate_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESModel NightSky_20;
    BSSimpleList_WeatherType_1a03eb11 WeatherList_48;
    TESTexture_fe82fffc SunSkyObject_58;
    TESTexture_fe82fffc SunGlareSkyObject_68;
    TESClimate__TimingData Timing_78;
};
static_assert(sizeof(TESClimate) == 128, "TESClimate layout differs from the PDB");
