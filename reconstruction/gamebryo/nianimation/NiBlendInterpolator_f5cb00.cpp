// Source exposure: binary-analysis (local target observations; labelled symbol names).
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// 0xf5cb00 NiBlendInterpolator::GuaranteeTimeRange
// Adapted bodies: none.
#include "NiBlendInterpolator_f5cb00.h"
void NiBlendInterpolator::GuaranteeTimeRange(float start, float end)
{
    if (unk1A == 1)
    {
        unk28->GuaranteeTimeRange(start, end);
        return;
    }
    for (std::uint8_t i = 0; i < unk19; ++i)
    {
        NiInterpolator* interpolator = unk20[i].interpolator;
        if (interpolator)
            interpolator->GuaranteeTimeRange(start, end);
    }
}
