// Source exposure: mixed (pinned image; cited community declarations and symbol layouts).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0xf80e80 NiLookAtInterpolator::GetActiveTimeRange
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// Cookbook: 0xf80e80 48
#include "NiLookAtInterpolator_f80e80.h"
#include <cfloat>

void NiLookAtInterpolator::GetActiveTimeRange(float& begin, float& end) const
{
    begin = FLT_MAX;
    end = -FLT_MAX;
    for (unsigned int i = 0; i < 3; ++i) {
        if (childInterpolators[i]) {
            float childBegin;
            float childEnd;
            childInterpolators[i]->GetActiveTimeRange(childBegin, childEnd);
            if (childBegin != childEnd) {
                if (childBegin < begin)
                    begin = childBegin;
                if (childEnd > end)
                    end = childEnd;
            }
        }
    }
    if (begin == FLT_MAX && end == -FLT_MAX) {
        begin = 0.0f;
        end = 0.0f;
    }
}
