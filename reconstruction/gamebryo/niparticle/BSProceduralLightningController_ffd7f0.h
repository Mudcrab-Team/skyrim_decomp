// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::GetInterpolatorIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// g_invalidInterpolatorIndex, g_procLightningIDNames: GUESS(low)
#pragma once

#include <cstdint>

extern const std::uint16_t g_invalidInterpolatorIndex;
extern const char* const g_procLightningIDNames[9];

class BSProceduralLightningController
{
public:
    std::uint16_t GetInterpolatorIndex(const char* a_id) const;
};
