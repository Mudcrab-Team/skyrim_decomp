// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x32d090 BGSTextureSet::InitializeData
// Adapted bodies: none
#include "BGSTextureSet.h"

void BGSTextureSet::InitializeData()
{
    for (std::uint32_t i = 0; i < 8; ++i) {
        textures[i].InitializeDataComponent();
    }
    unknownC0 = 0;
    unknownC8 = 0;
}
