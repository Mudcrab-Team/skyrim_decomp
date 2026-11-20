// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf6b510 NiBlendAccumTransformInterpolator::SupportsBlendValue
// Adapted bodies: none
#include "NiBlendAccumTransformInterpolator_f6b510.h"

bool NiBlendAccumTransformInterpolator::SupportsBlendValue(const BlendSourceInterpolator* input) const
{
    return input->IsTransformValueSupported();
}
