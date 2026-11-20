// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraSeenData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct SeenData;
struct ExtraSeenData {
    BSExtraData_4ca6af76 _base;
    SeenData* seenData;
};
static_assert(sizeof(ExtraSeenData) == 24, "ExtraSeenData layout differs from the PDB");
