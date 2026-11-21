// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: bhkShape; size 0x28
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "MATERIAL_ID.h"
#include "bhkSerializable.h"
struct bhkShape {
    bhkSerializable _base;
    MATERIAL_ID materialID;
    unsigned int filterInfo;
};
static_assert(sizeof(bhkShape) == 40, "bhkShape layout differs from the PDB");
