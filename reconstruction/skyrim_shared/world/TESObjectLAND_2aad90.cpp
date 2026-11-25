// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2aad90 TESObjectLAND::Function2aad90
// Adapted bodies: none.
#include "TESObjectLAND_2aad90.h"

// Finds the first empty slot among the first five quadrant textures.
std::int32_t TESObjectLAND::Function2aad90(std::uint8_t quadrant) const
{
    if (quadrant >= 4)
        return -1;
    LoadedLandData* data = loadedData;
    if (!data)
        return -1;
    std::uint32_t index = 0;
    TESLandTexture* const* texture = data->quadTextures[quadrant];
    while (index < 5) {
        if (!*texture)
            return index;
        ++index;
        ++texture;
    }
    return -1;
}
