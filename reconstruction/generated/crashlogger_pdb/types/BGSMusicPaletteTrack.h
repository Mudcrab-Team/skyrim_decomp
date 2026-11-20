// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicPaletteTrack; size 0x90
#pragma once

#include "BGSMusicTrack.h"
struct BGSMusicPaletteTrack {
    BGSMusicTrack _base;
    unsigned char layers_raw[72];
    int playingIndexes[3];
    float duration;
    float fadeOutTime;
    unsigned int pad7C;
    unsigned long long playTime;
    unsigned long long pauseTime;
};
static_assert(sizeof(BGSMusicPaletteTrack) == 144, "BGSMusicPaletteTrack layout differs from the PDB");
