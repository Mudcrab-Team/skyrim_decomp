// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SoundPlaybackCharacteristics; size 0x10
#pragma once

#include "BSIPlaybackCharacteristics.h"
struct SoundPlaybackCharacteristics {
    BSIPlaybackCharacteristics _base;
    unsigned char frequencyShift;
    unsigned char frequencyVariance;
    unsigned char priority;
    unsigned char dbVariance;
    unsigned short staticAttenuation;
    unsigned short pad0E;
};
static_assert(sizeof(SoundPlaybackCharacteristics) == 16, "SoundPlaybackCharacteristics layout differs from the PDB");
