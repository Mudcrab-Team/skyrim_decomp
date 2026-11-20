// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBlendAccumTransformInterpolator: EXE_RTTI
// SupportsBlendValue: GUESS(low)
#pragma once

#include "NiBlendInterpolator_f72bc0.h"

class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
{
public:
    bool SupportsBlendValue(const BlendSourceInterpolator* input) const;
};
