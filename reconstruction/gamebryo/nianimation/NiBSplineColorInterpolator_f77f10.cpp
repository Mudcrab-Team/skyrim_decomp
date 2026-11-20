// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf77f10 NiBSplineColorInterpolator::CopyMembers
// 0xf781a0 NiBSplineColorInterpolator::ctor
// 0xf781f0 NiBSplineColorInterpolator::ctor
// 0xf78390 NiBSplineColorInterpolator::GetChannelPosed
// 0xf783c0 NiBSplineColorInterpolator::GetChannelHandle
// 0xf783e0 NiBSplineColorInterpolator::SetChannelHandle
// 0xf784b0 NiBSplineColorInterpolator::dtor
#include "NiBSplineColorInterpolator_f77f10.h"

void NiBSplineColorInterpolator::CopyMembers(NiBSplineColorInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
    dest->channelHandle = channelHandle;
}

NiBSplineColorInterpolator::NiBSplineColorInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineInterpolator(data, basis), value{}, channelHandle(handle)
{
}

NiBSplineColorInterpolator::NiBSplineColorInterpolator(const NiColorA& value) :
    NiBSplineInterpolator(nullptr, nullptr), value(value), channelHandle(0xFFFFu)
{
}

bool NiBSplineColorInterpolator::GetChannelPosed(std::uint16_t channel) const
{
    constexpr std::uint16_t valueChannel = 0;
    bool posed = false;
    if (valueChannel == channel) {
        posed = GetControlPointCount(valueChannel) == 0;
    }
    return posed;
}

std::uint32_t NiBSplineColorInterpolator::GetChannelHandle(std::uint16_t channel) const
{
    if (channel != 0) {
        return 0xFFFFu;
    }
    return channelHandle;
}

void NiBSplineColorInterpolator::SetChannelHandle(std::uint32_t handle, std::uint16_t channel)
{
    if (channel == 0) {
        channelHandle = handle;
    }
}
