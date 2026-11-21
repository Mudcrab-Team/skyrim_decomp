// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkShape; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

#include "MATERIAL_ID.h"
#include "bhkSerializable_cf25f762.h"
struct bhkShape_a9c42bb4 {
    bhkSerializable_cf25f762 _base;
    MATERIAL_ID materialID;
    unsigned int filterInfo;
};
static_assert(sizeof(bhkShape_a9c42bb4) == 40, "bhkShape_a9c42bb4 layout differs from the PDB");
