// Source exposure: mixed (community declarations, symbol layouts, pinned-image observations).
// Code origin: original; body and bounded accessor reconstructed from local target observations
// SPDX-License-Identifier: CC0-1.0
// 0xf814b0 NiMorphData::RegisterStreamables
// NiMorphData::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
#include "NiMorphData_f814b0.h"

bool NiMorphData::RegisterStreamables(NiStream& stream)
{
    if (!NiObject::RegisterStreamables(stream)) {
        return false;
    }
    for (std::uint32_t index = 0; index < m_uiNumTargets; ++index) {
        stream.RegisterFixedString(GetTarget(index)->m_kName);
    }
    return true;
}
