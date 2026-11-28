// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x180dc0 GetLockDifficultyFromLevel180dc0
// Adapted bodies: none.
#include "FreeFunction_180dc0.h"

// Maps a numeric lock level to its difficulty rank (0..5) using the configured thresholds.
std::int32_t GetLockDifficultyFromLevel180dc0(std::int32_t a_level)
{
    if (a_level <= gLockLevelVeryEasy180dc0) {
        return 0;
    }
    if (a_level <= gLockLevelEasy180dc0) {
        return 1;
    }
    if (a_level <= gLockLevelAverage180dc0) {
        return 2;
    }
    if (a_level <= gLockLevelHard180dc0) {
        return 3;
    }
    return (a_level > gLockLevelVeryHard180dc0) ? 5 : 4;
}
