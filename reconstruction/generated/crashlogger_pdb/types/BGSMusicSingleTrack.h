// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicSingleTrack; size 0x80
#pragma once

#include "BGSMusicTrack.h"
#include "BSSoundHandle.h"
#include "BSTArray_float_ed3b09d0_c6f3c315.h"
#include "ID.h"
struct LoopData;
struct BGSMusicSingleTrack {
    BGSMusicTrack _base;
    ID trackID;
    ID finaleID;
    BSTArray_float_ed3b09d0_c6f3c315 cuePoints;
    unsigned int nextCuePoint;
    unsigned int loopsRemaining;
    unsigned int lastKnownPlaybackPosition;
    unsigned int pad5C;
    LoopData* loopData;
    BSSoundHandle trackHandle;
    BSSoundHandle finaleHandle;
};
static_assert(sizeof(BGSMusicSingleTrack) == 128, "BGSMusicSingleTrack layout differs from the PDB");
