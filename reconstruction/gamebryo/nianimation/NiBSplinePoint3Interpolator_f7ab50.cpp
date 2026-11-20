// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf7ab50 NiBSplinePoint3Interpolator::CopyMembers
// 0xf7add0 NiBSplinePoint3Interpolator::ctor
// 0xf7ae20 NiBSplinePoint3Interpolator::ctor
// 0xf7b000 NiBSplinePoint3Interpolator::GetChannelPosed
// 0xf7b030 NiBSplinePoint3Interpolator::GetChannelHandle
// 0xf7b050 NiBSplinePoint3Interpolator::SetChannelHandle
// 0xf7b120 NiBSplinePoint3Interpolator::dtor
#include "NiBSplinePoint3Interpolator_f7ab50.h"

void NiBSplinePoint3Interpolator::CopyMembers(NiBSplinePoint3Interpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineInterpolator::CopyMembers(dest, cloning);
    dest->value.x = value.x;
    dest->value.y = value.y;
    dest->value.z = value.z;
    dest->channelHandle = channelHandle;
}

NiBSplinePoint3Interpolator::NiBSplinePoint3Interpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineInterpolator(data, basis), value{}, channelHandle(handle)
{
}

NiBSplinePoint3Interpolator::NiBSplinePoint3Interpolator(const NiPoint3& value) :
    NiBSplineInterpolator(nullptr, nullptr), value{value.x, value.y, value.z}, channelHandle(0xFFFFu)
{
}

bool NiBSplinePoint3Interpolator::GetChannelPosed(std::uint16_t channel) const
{
    constexpr std::uint16_t valueChannel = 0;
    bool posed = false;
    if (valueChannel == channel) {
        posed = GetControlPointCount(valueChannel) == 0;
    }
    return posed;
}

std::uint32_t NiBSplinePoint3Interpolator::GetChannelHandle(std::uint16_t channel) const
{
    if (channel != 0) {
        return 0xFFFFu;
    }
    return channelHandle;
}

void NiBSplinePoint3Interpolator::SetChannelHandle(std::uint32_t handle, std::uint16_t channel)
{
    if (channel == 0) {
        channelHandle = handle;
    }
}
