// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf7ab90 NiBSplinePoint3Interpolator::LoadBinary
// 0xf7ac30 NiBSplinePoint3Interpolator::SaveBinary
// 0xf7aca0 NiBSplinePoint3Interpolator::IsEqual
// Adapted bodies: none
#include "NiBSplinePoint3Interpolator_f7ab90.h"

void NiBSplinePoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    value.LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(channelHandle);
    const auto transferred = binary->_readFn(binary, &channelHandle, sizeof(channelHandle), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplinePoint3Interpolator::SaveBinary(NiStream& stream)
{
    NiBSplineInterpolator::SaveBinary(stream);
    value.SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(channelHandle);
    const auto transferred = binary->_writeFn(binary, &channelHandle, sizeof(channelHandle), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplinePoint3Interpolator::IsEqual(NiObject* object)
{
    if (!NiBSplineInterpolator::IsEqual(object)) {
        return false;
    }
    const auto* other = static_cast<const NiBSplinePoint3Interpolator*>(object);
    if (value.x != other->value.x) {
        return false;
    }
    if (value.y != other->value.y) {
        return false;
    }
    if (value.z != other->value.z) {
        return false;
    }
    if (other->channelHandle != channelHandle) {
        return false;
    }
    return true;
}
