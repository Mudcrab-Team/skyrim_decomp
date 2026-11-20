// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESClimate; size 0x80
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSimpleList_RE__WeatherType_a132f962.h"
#include "TESForm.h"
#include "TESModel_c52655e4.h"
#include "Timing.h"
struct TESClimate_c9cfcf5f {
    TESForm _base;
    TESModel_c52655e4 nightSky;
    BSSimpleList_RE__WeatherType_a132f962 weatherList;
    unsigned char skyObjects_raw[32];
    Timing timing;
};
static_assert(sizeof(TESClimate_c9cfcf5f) == 128, "TESClimate_c9cfcf5f layout differs from the PDB");
