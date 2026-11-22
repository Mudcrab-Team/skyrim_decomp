// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf68630 NiBlendTransformInterpolator::~NiBlendTransformInterpolator
// CI hash: 0xf68630 ??_GNiBlendTransformInterpolator@@UEAAPEAXI@Z
// Adapted bodies: none
#include "NiBlendTransformInterpolator_f67ed0.h"

NiBlendTransformInterpolator::NiBlendTransformInterpolator() = default;

// The image's deleting wrapper calls the complete destructor out of line.
__declspec(noinline) NiBlendTransformInterpolator::~NiBlendTransformInterpolator() = default;
