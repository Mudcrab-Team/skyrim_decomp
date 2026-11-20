// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraRaceData; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
#include "NiPointer_RE__QueuedFile_61648701.h"
struct ExtraRaceData {
    BSExtraData_4ca6af76 _base;
    NiPointer_RE__QueuedFile_61648701 preloadedRaceData;
};
static_assert(sizeof(ExtraRaceData) == 24, "ExtraRaceData layout differs from the PDB");
