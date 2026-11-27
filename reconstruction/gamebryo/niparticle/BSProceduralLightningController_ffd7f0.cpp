// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::GetInterpolatorIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xffd7f0 BSProceduralLightningController::GetInterpolatorIndex
#include "BSProceduralLightningController_ffd7f0.h"

#include <cstring>

// Find the interpolator slot index matching the given identifier string.
std::uint16_t BSProceduralLightningController::GetInterpolatorIndex(const char* a_id) const
{
    std::uint16_t result = g_invalidInterpolatorIndex;
    for (std::uint16_t i = 0; i < 9; ++i) {
        if (std::strcmp(g_procLightningIDNames[i], a_id) == 0) {
            result = i;
        }
    }
    return result;
}
