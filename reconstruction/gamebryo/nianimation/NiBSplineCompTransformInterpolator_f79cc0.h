// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineCompTransformInterpolator: EXE_RTTI
// NiBSplineTransformInterpolator: STANDIN EXE_RTTI
// unknown30, compressionParameters: GUESS(low)
#pragma once

#include "NiBSplineInterpolator_f77f50.h"
#include <limits>

class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    NiBSplineTransformInterpolator(NiBSplineData* data, std::uint32_t translationHandle, std::uint32_t rotationHandle, std::uint32_t scaleHandle, NiBSplineBasisData* basis);

private:
    std::uint8_t unknown30[0x30];
};

class NiBSplineCompTransformInterpolator : public NiBSplineTransformInterpolator
{
public:
    NiBSplineCompTransformInterpolator(NiBSplineData* data, std::uint32_t translationHandle, std::uint32_t rotationHandle, std::uint32_t scaleHandle, NiBSplineBasisData* basis);

private:
    float compressionParameters[6];
};
