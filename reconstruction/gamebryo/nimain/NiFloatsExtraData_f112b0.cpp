// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf112b0 NiFloatsExtraData::CopyMembers
// 0xf11870 NiFloatsExtraData::GetValue
// Adapted bodies: none
#include "NiFloatsExtraData_f112b0.h"

void* AllocateExtraData(std::size_t bytes);

void NiFloatsExtraData::CopyMembers(NiFloatsExtraData* dest)
{
    NiExtraData::CopyMembers(dest);
    if (value && size) {
        dest->size = size;
        dest->value = static_cast<float*>(AllocateExtraData(size * sizeof(*value)));
        for (std::uint32_t index = 0; index < size; ++index) {
            dest->value[index] = value[index];
        }
        return;
    }
    dest->value = nullptr;
    dest->size = 0;
}

float NiFloatsExtraData::GetValue(std::uint32_t index) const
{
    return index < size ? value[index] : 0.0f;
}
