// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// NiBSplineTransformInterpolator: EXE_RTTI
// CopyMembers, GetChannelComponentCount, GetChannelDegree, GetChannelHandle, SetChannelHandle, value, translationHandle, rotationHandle, scaleHandle: GUESS(low)
#pragma once

#include "NiBSplineInterpolator.h"

// NiPoint3, NiPoint3::x, ::y, ::z, NiQuaternion, NiQuaternion::w, ::x, ::y, ::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class NiQuaternion
{
public:
    float w;
    float x;
    float y;
    float z;
};

// NiQuatTransform: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// translation, rotation, scale: GUESS(low); component types follow their measured layout.
class NiQuatTransform
{
public:
    NiPoint3 translation;
    NiQuaternion rotation;
    float scale;
};
static_assert(sizeof(NiQuatTransform) == 0x20, "quaternion transform size");

class NiBSplineTransformInterpolator : public NiBSplineInterpolator
{
public:
    NiBSplineTransformInterpolator();
    void CopyMembers(NiBSplineTransformInterpolator* dest, NiCloningProcess& cloning);
    std::uint32_t GetChannelComponentCount(std::uint16_t channel) const;
    std::uint32_t GetChannelDegree(std::uint16_t channel) const;
    std::uint32_t GetChannelHandle(std::uint16_t channel) const;
    void SetChannelHandle(std::uint32_t handle, std::uint16_t channel);
    ~NiBSplineTransformInterpolator() override = default;

private:
    NiQuatTransform value;
    std::uint32_t translationHandle;
    std::uint32_t rotationHandle;
    std::uint32_t scaleHandle;
};
static_assert(sizeof(NiBSplineTransformInterpolator) == 0x60, "transform spline size");
