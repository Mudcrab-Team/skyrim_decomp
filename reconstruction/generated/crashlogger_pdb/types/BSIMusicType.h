// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSIMusicType; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BSIMusicTrack_2b5885c8_f0523254.h"
#include "BSTArray_unsigned_int_4b643186_a626a7e9.h"
#include "MST.h"
#include "MUSIC_STATUS.h"
struct BSIMusicType_vtbl_ef367625;
struct BSIMusicType {
    BSIMusicType_vtbl_ef367625* __vftable;
    MST flags;
    unsigned char priority;
    unsigned char padding;
    unsigned short ducksOtherMusicBy;
    float fadeTime;
    unsigned int currentTrackIndex;
    BSTArray_unsigned_int_4b643186_a626a7e9 trackHistory;
    BSTArray_RE__BSIMusicTrack_2b5885c8_f0523254 tracks;
    MUSIC_STATUS typeStatus;
    unsigned int pad4C;
};
static_assert(sizeof(BSIMusicType) == 80, "BSIMusicType layout differs from the PDB");
