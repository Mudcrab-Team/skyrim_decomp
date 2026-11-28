// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xf6e870 NiKeyBasedInterpolator::GetActiveTimeRange_140CDC7B0
#include "NiKeyBasedInterpolator_f6e870.h"

#include <cfloat>

// Compute the minimum begin time and maximum end time across all animation key channels.
void NiKeyBasedInterpolator::GetActiveTimeRange_140CDC7B0(float& a_begin, float& a_end) const
{
    a_begin = FLT_MAX;
    a_end = -FLT_MAX;

    for (std::uint16_t ch = 0; ch < GetKeyChannelCount(); ++ch) {
        NiAnimationKeyf6e870* first = GetKeyAt(0, ch);
        NiAnimationKeyf6e870* last = GetKeyAt(GetKeyCount(ch) - 1, ch);
        if (first && last) {
            if (first->time < a_begin) {
                a_begin = first->time;
            }
            if (last->time > a_end) {
                a_end = last->time;
            }
        }
    }

    if (a_begin == FLT_MAX && a_end == -FLT_MAX) {
        a_begin = 0.0f;
        a_end = 0.0f;
    }
}
