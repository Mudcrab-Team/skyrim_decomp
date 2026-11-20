// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf7a420 NiBSplineFloatInterpolator::CopyMembers
// 0xf7a6c0 NiBSplineFloatInterpolator::ctor
// 0xf7a700 NiBSplineFloatInterpolator::ctor
// 0xf7a890 NiBSplineFloatInterpolator::GetChannelPosed
// 0xf7a8e0 NiBSplineFloatInterpolator::SetChannelHandle
#include "NiBSplineFloatInterpolator_f7a420.h"

void NiBSplineFloatInterpolator::CopyMembers(NiBSplineFloatInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
    dest->channelHandle = channelHandle;
}

NiBSplineFloatInterpolator::NiBSplineFloatInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineInterpolator(data, basis), value(0.0f), channelHandle(handle)
{
}

NiBSplineFloatInterpolator::NiBSplineFloatInterpolator(float value) :
    NiBSplineInterpolator(nullptr, nullptr), value(value), channelHandle(0xFFFFu)
{
}

bool NiBSplineFloatInterpolator::GetChannelPosed(std::uint16_t channel) const
{
    constexpr std::uint16_t floatChannel = 0;
    bool posed = false;
    if (floatChannel == channel) {
        posed = GetControlPointCount(floatChannel) == 0;
    }
    return posed;
}

void NiBSplineFloatInterpolator::SetChannelHandle(std::uint32_t handle, std::uint16_t channel)
{
    if (channel == 0) {
        channelHandle = handle;
    }
}
