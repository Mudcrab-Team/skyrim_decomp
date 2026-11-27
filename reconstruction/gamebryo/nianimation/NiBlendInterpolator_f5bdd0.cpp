// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendInterpolator, NiBlendInterpolator::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0xf5bdd0 NiBlendInterpolator::RegisterStreamables
#include "NiBlendInterpolator_f5bdd0.h"

bool NiBlendInterpolator::RegisterStreamables(NiStream& stream)
{
    if (!NiInterpolator::RegisterStreamables(stream))
        return false;
    if (!(flags & 1)) {
        for (std::uint8_t i = 0; i < arraySize; ++i) {
            if (interpArray[i].interpolator)
                interpArray[i].interpolator->RegisterStreamables(stream);
        }
    }
    return true;
}
