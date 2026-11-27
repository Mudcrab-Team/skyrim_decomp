// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x528b30 TESWaterDisplacement::Function528b30
#include "TESWaterDisplacement_528b30.h"

std::uint32_t TESWaterDisplacement::Function528b30()
{
    if (unk1C == 0 && g_displacementCount < 7)
    {
        unk1C = ++g_displacementCount;
        if (displacementGeometry)
        {
            BSGeometry* geometry = displacementGeometry->AsGeometry();
            if (geometry)
            {
                geometry->effectShaderProperty->unk8C = 1 << unk1C;
            }
        }
    }
    return unk1C;
}
