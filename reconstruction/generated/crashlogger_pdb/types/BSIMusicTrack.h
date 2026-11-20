// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicTrack; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "MUSIC_STATUS.h"
struct BSIMusicTrack_vtbl;
struct BSIMusicTrack {
    BSIMusicTrack_vtbl* __vftable;
    MUSIC_STATUS trackStatus;
    unsigned int pad0C;
};
static_assert(sizeof(BSIMusicTrack) == 16, "BSIMusicTrack layout differs from the PDB");
