// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf79cc0 NiBSplineCompTransformInterpolator::Ctor
// Adapted bodies: none
#include "NiBSplineCompTransformInterpolator_f79cc0.h"

NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator(NiBSplineData* data, std::uint32_t translationHandle, std::uint32_t rotationHandle, std::uint32_t scaleHandle, NiBSplineBasisData* basis) :
    NiBSplineTransformInterpolator(data, translationHandle, rotationHandle, scaleHandle, basis)
{
    compressionParameters[0] = std::numeric_limits<float>::max();
    compressionParameters[1] = std::numeric_limits<float>::max();
    compressionParameters[2] = std::numeric_limits<float>::max();
    compressionParameters[3] = std::numeric_limits<float>::max();
    compressionParameters[4] = std::numeric_limits<float>::max();
    compressionParameters[5] = std::numeric_limits<float>::max();
}
