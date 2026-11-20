// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf78cc0 NiBSplineCompFloatInterpolator::CopyMembers
// 0xf78d00 NiBSplineCompFloatInterpolator::LoadBinary
// 0xf78d90 NiBSplineCompFloatInterpolator::SaveBinary
// 0xf78df0 NiBSplineCompFloatInterpolator::IsEqual
// 0xf78f20 NiBSplineCompFloatInterpolator::ctor(NiBSplineData*, std::uint32_t, NiBSplineBasisData*)
// 0xf78f60 NiBSplineCompFloatInterpolator::ctor(float)
// 0xf791a0 NiBSplineCompFloatInterpolator::dtor
#include "NiBSplineCompFloatInterpolator_f78cc0.h"

#include <limits>

namespace
{
constexpr float invalidCompressionParameter = std::numeric_limits<float>::max();
}

void NiBSplineCompFloatInterpolator::CopyMembers(NiBSplineCompFloatInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineFloatInterpolator::CopyMembers(dest, cloning);
    dest->compressionParameters[0] = compressionParameters[0];
    dest->compressionParameters[1] = compressionParameters[1];
}

void NiBSplineCompFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineFloatInterpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_readFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplineCompFloatInterpolator::SaveBinary(NiStream& stream)
{
    NiBSplineFloatInterpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_writeFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplineCompFloatInterpolator::IsEqual(NiObject* other)
{
    if (!NiBSplineFloatInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* spline = static_cast<const NiBSplineCompFloatInterpolator*>(other);
    for (std::uint32_t i = 0; i < 2; ++i) {
        if (compressionParameters[i] != spline->compressionParameters[i]) {
            return false;
        }
    }
    return true;
}

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineFloatInterpolator(data, handle, basis)
{
    compressionParameters[0] = invalidCompressionParameter;
    compressionParameters[1] = invalidCompressionParameter;
}

NiBSplineCompFloatInterpolator::NiBSplineCompFloatInterpolator(float value) :
    NiBSplineFloatInterpolator(value)
{
    compressionParameters[0] = invalidCompressionParameter;
    compressionParameters[1] = invalidCompressionParameter;
}
