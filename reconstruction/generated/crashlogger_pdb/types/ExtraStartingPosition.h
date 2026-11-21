// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraStartingPosition; size 0x30
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "FILE_POS_ROT.h"
struct BGSLocation;
struct ExtraStartingPosition {
    BSExtraData_4ca6af76 _base;
    FILE_POS_ROT startPosition;
    BGSLocation* location;
};
static_assert(sizeof(ExtraStartingPosition) == 48, "ExtraStartingPosition layout differs from the PDB");
