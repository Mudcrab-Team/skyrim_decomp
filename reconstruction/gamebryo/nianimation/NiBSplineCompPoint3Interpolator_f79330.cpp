// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf79330 NiBSplineCompPoint3Interpolator::CopyMembers
// 0xf79370 NiBSplineCompPoint3Interpolator::LoadBinary
// 0xf79400 NiBSplineCompPoint3Interpolator::SaveBinary
// 0xf79460 NiBSplineCompPoint3Interpolator::IsEqual
// 0xf79590 NiBSplineCompPoint3Interpolator::ctor(NiBSplineData*, std::uint32_t, NiBSplineBasisData*)
// 0xf795d0 NiBSplineCompPoint3Interpolator::ctor(const NiPoint3&)
// 0xf79850 NiBSplineCompPoint3Interpolator::dtor
#include "NiBSplineCompPoint3Interpolator_f79330.h"

#include <limits>

namespace
{
constexpr float invalidCompressionParameter = std::numeric_limits<float>::max();
}

void NiBSplineCompPoint3Interpolator::CopyMembers(NiBSplineCompPoint3Interpolator* dest, NiCloningProcess& cloning)
{
    NiBSplinePoint3Interpolator::CopyMembers(dest, cloning);
    dest->compressionParameters[0] = compressionParameters[0];
    dest->compressionParameters[1] = compressionParameters[1];
}

void NiBSplineCompPoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiBSplinePoint3Interpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_readFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplineCompPoint3Interpolator::SaveBinary(NiStream& stream)
{
    NiBSplinePoint3Interpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_writeFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplineCompPoint3Interpolator::IsEqual(NiObject* other)
{
    if (!NiBSplinePoint3Interpolator::IsEqual(other)) {
        return false;
    }
    const auto* spline = static_cast<const NiBSplineCompPoint3Interpolator*>(other);
    for (std::uint32_t i = 0; i < 2; ++i) {
        if (compressionParameters[i] != spline->compressionParameters[i]) {
            return false;
        }
    }
    return true;
}

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplinePoint3Interpolator(data, handle, basis)
{
    compressionParameters[0] = invalidCompressionParameter;
    compressionParameters[1] = invalidCompressionParameter;
}

NiBSplineCompPoint3Interpolator::NiBSplineCompPoint3Interpolator(const NiPoint3& value) :
    NiBSplinePoint3Interpolator(value)
{
    compressionParameters[0] = invalidCompressionParameter;
    compressionParameters[1] = invalidCompressionParameter;
}
