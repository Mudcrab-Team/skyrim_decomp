// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14f4370 TESImagespaceManager::UpdateActiveEOFEffectCount
#include "TESImagespaceManager_14f4370.h"

bool g_effectsEnabled;

void TESImagespaceManager::UpdateActiveEOFEffectCount()
{
    unk40 = -1;
    unk3C = 0;
    if (g_effectsEnabled)
    {
        for (std::int32_t i = 0; i < 8; ++i)
        {
            ImageSpaceEffect* effect = effects[i];
            if (effect && effect->IsActive())
            {
                ++unk3C;
                unk40 = i;
            }
        }
    }
}
