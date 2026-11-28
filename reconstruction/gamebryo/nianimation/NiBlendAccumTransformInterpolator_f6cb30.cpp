// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf6cb30 NiBlendAccumTransformInterpolator::ctor
#include "NiBlendAccumTransformInterpolator_f6cb30.h"

// Construct a blend-accum transform interpolator with an invalidated accumulated transform.
NiBlendAccumTransformInterpolator::NiBlendAccumTransformInterpolator() :
    NiBlendInterpolator(),
    accumValue(),
    unk68(0),
    unk70(false)
{
}
