// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf687b0 NiBlendFloatInterpolator::CopyMembers
// 0xf687e0 NiBlendFloatInterpolator::LoadBinary
// 0xf68860 NiBlendFloatInterpolator::SaveBinary
// 0xf688c0 NiBlendFloatInterpolator::IsEqual
// 0xf68c20 NiBlendFloatInterpolator::SupportsBlendValue
// 0xf68ef0 NiBlendFloatInterpolator::dtor
// CI hash: 0xf68ef0 ??_GNiBlendFloatInterpolator@@UEAAPEAXI@Z
#include "NiBlendFloatInterpolator_f687b0.h"

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiBlendFloatInterpolator::NiBlendFloatInterpolator() = default;

void NiBlendFloatInterpolator::CopyMembers(NiBlendFloatInterpolator* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
}

void NiBlendFloatInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_readFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBlendFloatInterpolator::SaveBinary(NiStream& stream)
{
    NiBlendInterpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_writeFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBlendFloatInterpolator::IsEqual(NiObject* other)
{
    if (!NiBlendInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* blend = static_cast<const NiBlendFloatInterpolator*>(other);
    if (value != blend->value) {
        return false;
    }
    return true;
}

bool NiBlendFloatInterpolator::SupportsBlendValue(const BlendValueSupport* input) const
{
    return input->IsFloatValueSupported();
}
