// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESGrass; size 0x78
#pragma once

#include "GRASS_DATA.h"
#include "TESBoundObject.h"
#include "TESModel.h"
struct TESGrass {
    TESBoundObject _base;
    TESModel _base_TESModel;
    GRASS_DATA data;
};
static_assert(sizeof(TESGrass) == 120, "TESGrass layout differs from the PDB");
