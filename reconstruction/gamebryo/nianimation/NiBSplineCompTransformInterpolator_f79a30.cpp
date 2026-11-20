// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf79a30 NiBSplineCompTransformInterpolator::CopyMembers
// 0xf79a80 NiBSplineCompTransformInterpolator::LoadBinary
// 0xf79b10 NiBSplineCompTransformInterpolator::SaveBinary
// 0xf79b70 NiBSplineCompTransformInterpolator::IsEqual
// 0xf7a290 NiBSplineCompTransformInterpolator::dtor
#include "NiBSplineCompTransformInterpolator_f79a30.h"

// The constructor emits the compiler-generated deleting destructor.
NiBSplineCompTransformInterpolator::NiBSplineCompTransformInterpolator() = default;

void NiBSplineCompTransformInterpolator::CopyMembers(NiBSplineCompTransformInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineTransformInterpolator::CopyMembers(dest, cloning);
    dest->compressionParameters[0] = compressionParameters[0];
    dest->compressionParameters[1] = compressionParameters[1];
    dest->compressionParameters[2] = compressionParameters[2];
    dest->compressionParameters[3] = compressionParameters[3];
    dest->compressionParameters[4] = compressionParameters[4];
    dest->compressionParameters[5] = compressionParameters[5];
}

void NiBSplineCompTransformInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineTransformInterpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_readFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplineCompTransformInterpolator::SaveBinary(NiStream& stream)
{
    NiBSplineTransformInterpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_writeFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplineCompTransformInterpolator::IsEqual(NiObject* other)
{
    if (!NiBSplineTransformInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* spline = static_cast<const NiBSplineCompTransformInterpolator*>(other);
    for (std::uint32_t i = 0; i < 6; ++i) {
        if (compressionParameters[i] != spline->compressionParameters[i]) {
            return false;
        }
    }
    return true;
}
