// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineTransformInterpolator: EXE_RTTI
// NiPoint3, NiQuaternion, NiQuatTransform, w, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// value, translationHandle, rotationHandle, scaleHandle, translation, rotation, scale: GUESS(low)
#pragma once

#include "NiBSplineInterpolator_f77f50.h"

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiQuaternion
{
    float w;
    float x;
    float y;
    float z;
};

struct NiQuatTransform
{
    NiPoint3 translation;
    NiQuaternion rotation;
    float scale;
};

class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    NiBSplineTransformInterpolator(const NiQuatTransform& pose);

private:
    NiQuatTransform value;
    std::uint32_t translationHandle;
    std::uint32_t rotationHandle;
    std::uint32_t scaleHandle;
};
