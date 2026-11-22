// Source exposure: mixed (community declarations; the pinned image listing).
// Code origin: original; the listing and community names only
// SPDX-License-Identifier: CC0-1.0
// 0xf7a870 NiBSplineFloatInterpolator::Functionf7a870
// 0xf7a8c0 NiBSplineFloatInterpolator::Functionf7a8c0
// Adapted bodies: none
#include "NiBSplineFloatInterpolator_f7a870.h"

std::uint32_t NiBSplineFloatInterpolator::Functionf7a870(std::uint16_t a_channel) const
{
    if (0 == a_channel) {
        return 3;
    }

    return 0;
}

std::uint32_t NiBSplineFloatInterpolator::Functionf7a8c0(std::uint16_t a_channel) const
{
    if (a_channel != 0) {
        return 0xFFFF;
    }

    return controlHandle;
}
