// Source exposure: mixed (community declarations, symbol layouts, pinned-image observations).
// Code origin: original; body reconstructed from local target observations
// SPDX-License-Identifier: CC0-1.0
// 0xf98290 NiFloatController::RegisterStreamables
// NiFloatController::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
#include "NiFloatController_f98290.h"

bool NiFloatController::RegisterStreamables(NiStream& stream)
{
    if (!NiTimeController::RegisterStreamables(stream)) {
        return false;
    }
    m_spFloatData->RegisterStreamables(stream);
    return true;
}
