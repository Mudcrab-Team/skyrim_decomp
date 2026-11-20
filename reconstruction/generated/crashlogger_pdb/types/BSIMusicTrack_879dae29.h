// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicTrack; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "MUSIC_STATUS.h"
struct BSIMusicTrack__VFTable;
struct BSIMusicTrack_879dae29 {
    BSIMusicTrack__VFTable* vftable_BSIMusicTrack_0;
    MUSIC_STATUS trackStatus;
    unsigned int pad0C;
};
static_assert(sizeof(BSIMusicTrack_879dae29) == 16, "BSIMusicTrack_879dae29 layout differs from the PDB");
