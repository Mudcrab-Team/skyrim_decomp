// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf6e600 NiKeyBasedInterpolator::~NiKeyBasedInterpolator
// 0xf6e6d0 NiKeyBasedInterpolator::GetKeyAt
// Adapted bodies: none
#include "NiKeyBasedInterpolator_f6e600.h"

NiKeyBasedInterpolator::~NiKeyBasedInterpolator()
{
    // The base destructor clears the interpolator state.
}

std::uint8_t* NiKeyBasedInterpolator::GetKeyAt(std::uint32_t index, std::uint16_t channel) const
{
    const auto stride = GetKeyStride(channel);
    return GetKeyArray(channel) + index * stride;
}
