// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf7b320 NiBSplineTransformInterpolator::CopyMembers
// 0xf7bc20 NiBSplineTransformInterpolator::GetChannelComponentCount
// 0xf7bc50 NiBSplineTransformInterpolator::GetChannelDegree
// 0xf7bd00 NiBSplineTransformInterpolator::GetChannelHandle
// 0xf7bd30 NiBSplineTransformInterpolator::SetChannelHandle
// 0xf7be60 NiBSplineTransformInterpolator::dtor
#include "NiBSplineTransformInterpolator_f7b320.h"

// The out-of-line constructor emits the compiler-generated deleting destructor.
NiBSplineTransformInterpolator::NiBSplineTransformInterpolator() :
    NiBSplineInterpolator(nullptr, nullptr)
{
}

void NiBSplineTransformInterpolator::CopyMembers(NiBSplineTransformInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineInterpolator::CopyMembers(dest, cloning);
    dest->value.translation.x = value.translation.x;
    dest->value.translation.y = value.translation.y;
    dest->value.translation.z = value.translation.z;
    dest->value.rotation = value.rotation;
    dest->value.scale = value.scale;
    dest->translationHandle = translationHandle;
    dest->rotationHandle = rotationHandle;
    dest->scaleHandle = scaleHandle;
}

std::uint32_t NiBSplineTransformInterpolator::GetChannelComponentCount(std::uint16_t channel) const
{
    switch (channel) {
    case 0:
        return 3;
    case 1:
        return 4;
    case 2:
        return 1;
    default:
        return 0;
    }
}

std::uint32_t NiBSplineTransformInterpolator::GetChannelDegree(std::uint16_t channel) const
{
    switch (channel) {
    case 0:
        return 3;
    case 1:
        return 3;
    case 2:
        return 3;
    default:
        return 0;
    }
}

std::uint32_t NiBSplineTransformInterpolator::GetChannelHandle(std::uint16_t channel) const
{
    switch (channel) {
    case 0:
        return translationHandle;
    case 1:
        return rotationHandle;
    case 2:
        return scaleHandle;
    default:
        return 0xFFFFu;
    }
}

void NiBSplineTransformInterpolator::SetChannelHandle(std::uint32_t handle, std::uint16_t channel)
{
    switch (channel) {
    case 0:
        translationHandle = handle;
        break;
    case 1:
        rotationHandle = handle;
        break;
    case 2:
        scaleHandle = handle;
        break;
    }
}
