// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf629c0 NiColorInterpolator::GetChannelPosed
// Adapted bodies: none
#include "NiColorInterpolator_f629c0.h"

bool NiColorInterpolator::GetChannelPosed(std::uint16_t) const
{
    return !colorData && (invalidColor.red != colorValue.red ||
                         invalidColor.green != colorValue.green ||
                         invalidColor.blue != colorValue.blue ||
                         invalidColor.alpha != colorValue.alpha);
}
