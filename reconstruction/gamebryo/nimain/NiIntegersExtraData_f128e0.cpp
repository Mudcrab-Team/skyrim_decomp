// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf128e0 NiIntegersExtraData::SetValues
// Adapted bodies: none
#include "NiIntegersExtraData_f128e0.h"

void FreeExtraData(void* allocation);
void* AllocateExtraData(std::size_t bytes);

void NiIntegersExtraData::SetValues(std::uint32_t count, const std::int32_t* elements)
{
    FreeExtraData(value);
    if (elements && count) {
        size = count;
        value = static_cast<std::int32_t*>(AllocateExtraData(count * sizeof(*value)));
        std::size_t index = 0;
        std::size_t remaining = count;
        do {
            value[index] = elements[index];
            ++index;
        } while (--remaining != 0);
        return;
    }
    size = 0;
    value = nullptr;
}
