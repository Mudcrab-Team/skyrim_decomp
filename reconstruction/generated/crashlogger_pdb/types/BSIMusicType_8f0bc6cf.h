// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicType; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BSIMusicTrack_2b5885c8.h"
#include "BSTArray_unsigned_int_4b643186.h"
#include "MST.h"
#include "MUSIC_STATUS.h"
struct BSIMusicType_vtbl;
struct BSIMusicType_8f0bc6cf {
    BSIMusicType_vtbl* __vftable;
    MST flags;
    unsigned char priority;
    unsigned char padding;
    unsigned short ducksOtherMusicBy;
    float fadeTime;
    unsigned int currentTrackIndex;
    BSTArray_unsigned_int_4b643186 trackHistory;
    BSTArray_RE__BSIMusicTrack_2b5885c8 tracks;
    MUSIC_STATUS typeStatus;
    unsigned int pad4C;
};
static_assert(sizeof(BSIMusicType_8f0bc6cf) == 80, "BSIMusicType_8f0bc6cf layout differs from the PDB");
