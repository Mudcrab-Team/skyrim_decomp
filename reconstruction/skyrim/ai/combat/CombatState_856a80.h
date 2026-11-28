// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CombatState, CombatState::BoostConfidence: CRASHLOGGER_PDB(59818@2026.10.24)
// GetConfidenceLevel, gConfidenceThreshold, confidenceLevel, unknown00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

float GetConfidenceLevel(std::uint8_t a_level);
extern const float gConfidenceThreshold;

class CombatState
{
public:
    bool BoostConfidence();  // compared: 0x856a80

    std::uint8_t unknown00[0x6D];
    std::uint8_t confidenceLevel;  // 6D
};
static_assert(offsetof(CombatState, confidenceLevel) == 0x6D, "confidenceLevel offset");
