// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf78640 NiBSplineCompColorInterpolator::CopyMembers
// 0xf78680 NiBSplineCompColorInterpolator::LoadBinary
// 0xf78710 NiBSplineCompColorInterpolator::SaveBinary
// 0xf78770 NiBSplineCompColorInterpolator::IsEqual
// 0xf788a0 NiBSplineCompColorInterpolator::ctor
// CI hash: 0xf788a0 ??0NiBSplineCompColorInterpolator@@QEAA@PEAVNiBSplineData@@IPEAVNiBSplineBasisData@@@Z
// 0xf788e0 NiBSplineCompColorInterpolator::ctor
// CI hash: 0xf788e0 ??0NiBSplineCompColorInterpolator@@QEAA@AEBVNiColorA@@@Z
// 0xf78b30 NiBSplineCompColorInterpolator::dtor
#include "NiBSplineCompColorInterpolator_f78640.h"

#include <limits>

void NiBSplineCompColorInterpolator::CopyMembers(NiBSplineCompColorInterpolator* dest, NiCloningProcess& cloning)
{
    NiBSplineColorInterpolator::CopyMembers(dest, cloning);
    dest->compressionParameters[0] = compressionParameters[0];
    dest->compressionParameters[1] = compressionParameters[1];
}

void NiBSplineCompColorInterpolator::LoadBinary(NiStream& stream)
{
    NiBSplineColorInterpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_readFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBSplineCompColorInterpolator::SaveBinary(NiStream& stream)
{
    NiBSplineColorInterpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(float);
    const auto transferred = binary->_writeFn(binary, compressionParameters, sizeof(compressionParameters), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBSplineCompColorInterpolator::IsEqual(NiObject* other)
{
    if (!NiBSplineColorInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* spline = static_cast<const NiBSplineCompColorInterpolator*>(other);
    for (std::uint32_t i = 0; i < 2; ++i) {
        if (compressionParameters[i] != spline->compressionParameters[i]) {
            return false;
        }
    }
    return true;
}

NiBSplineCompColorInterpolator::NiBSplineCompColorInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineColorInterpolator(data, handle, basis)
{
    compressionParameters[0] = std::numeric_limits<float>::max();
    compressionParameters[1] = std::numeric_limits<float>::max();
}

NiBSplineCompColorInterpolator::NiBSplineCompColorInterpolator(const NiColorA& value) :
    NiBSplineColorInterpolator(value)
{
    compressionParameters[0] = std::numeric_limits<float>::max();
    compressionParameters[1] = std::numeric_limits<float>::max();
}
