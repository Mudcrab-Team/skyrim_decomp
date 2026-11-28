// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// GetLockDifficultyFromLevel180dc0, gLockLevelVeryEasy180dc0, gLockLevelEasy180dc0, gLockLevelAverage180dc0, gLockLevelHard180dc0, gLockLevelVeryHard180dc0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::int32_t gLockLevelVeryEasy180dc0;
extern std::int32_t gLockLevelEasy180dc0;
extern std::int32_t gLockLevelAverage180dc0;
extern std::int32_t gLockLevelHard180dc0;
extern std::int32_t gLockLevelVeryHard180dc0;

std::int32_t GetLockDifficultyFromLevel180dc0(std::int32_t a_level);  // compared: 0x180dc0
