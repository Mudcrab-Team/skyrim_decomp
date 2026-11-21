// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf77f50 NiBSplineColorInterpolator::LoadBinary
// 0xf77ff0 NiBSplineColorInterpolator::SaveBinary
// 0xf78060 NiBSplineColorInterpolator::IsEqual
// Adapted bodies: none
#include "NiBSplineColorInterpolator_f77f50.h"

void NiBSplineColorInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineInterpolator::LoadBinary(stream);
    value.LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(channelHandle);
    const auto transferred = binary->_readFn(binary, &channelHandle, sizeof(channelHandle), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplineColorInterpolator::SaveBinary(NiStream& stream)
{
    NiBSplineInterpolator::SaveBinary(stream);
    value.SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(channelHandle);
    const auto transferred = binary->_writeFn(binary, &channelHandle, sizeof(channelHandle), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplineColorInterpolator::IsEqual(NiObject* object)
{
    if (!NiBSplineInterpolator::IsEqual(object)) {
        return false;
    }
    const auto* other = static_cast<const NiBSplineColorInterpolator*>(object);
    if (value.red != other->value.red) {
        return false;
    }
    if (value.green != other->value.green) {
        return false;
    }
    if (value.blue != other->value.blue) {
        return false;
    }
    if (value.alpha != other->value.alpha) {
        return false;
    }
    if (other->channelHandle != channelHandle) {
        return false;
    }
    return true;
}
