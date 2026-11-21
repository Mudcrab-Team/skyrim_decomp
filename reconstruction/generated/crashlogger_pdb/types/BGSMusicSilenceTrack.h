// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMusicSilenceTrack; size 0x38
#pragma once

#include "BGSMusicTrack.h"
struct BGSMusicSilenceTrack {
    BGSMusicTrack _base;
    float duration;
    unsigned int pad24;
    unsigned long long playTime;
    unsigned long long pauseTime;
};
static_assert(sizeof(BGSMusicSilenceTrack) == 56, "BGSMusicSilenceTrack layout differs from the PDB");
