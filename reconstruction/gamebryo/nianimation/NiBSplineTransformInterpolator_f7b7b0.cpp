// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf7b7b0 NiBSplineTransformInterpolator::Ctor
// Adapted bodies: none
#include "NiBSplineTransformInterpolator_f7b7b0.h"

NiBSplineTransformInterpolator::NiBSplineTransformInterpolator(const NiQuatTransform& pose) :
    NiBSplineInterpolator(nullptr, nullptr)
{
    value.translation.x = pose.translation.x;
    value.translation.y = pose.translation.y;
    value.translation.z = pose.translation.z;
    value.rotation = pose.rotation;
    value.scale = pose.scale;
    translationHandle = 0xFFFFu;
    rotationHandle = 0xFFFFu;
    scaleHandle = 0xFFFFu;
}
