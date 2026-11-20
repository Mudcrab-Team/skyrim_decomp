// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf729a0 NiBlendBoolInterpolator::CopyMembers
// 0xf729d0 NiBlendBoolInterpolator::LoadBinary
// 0xf72a50 NiBlendBoolInterpolator::SaveBinary
// 0xf72ab0 NiBlendBoolInterpolator::IsEqual
// 0xf72e30 NiBlendBoolInterpolator::SupportsBlendValue
// 0xf73110 NiBlendBoolInterpolator::dtor
#include "NiBlendBoolInterpolator_f729a0.h"

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiBlendBoolInterpolator::NiBlendBoolInterpolator() = default;

void NiBlendBoolInterpolator::CopyMembers(NiBlendBoolInterpolator* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
}

void NiBlendBoolInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_readFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiBlendBoolInterpolator::SaveBinary(NiStream& stream)
{
    NiBlendInterpolator::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_writeFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

bool NiBlendBoolInterpolator::IsEqual(NiObject* other)
{
    if (!NiBlendInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* blend = static_cast<const NiBlendBoolInterpolator*>(other);
    if (value != blend->value) {
        return false;
    }
    return true;
}

bool NiBlendBoolInterpolator::SupportsBlendValue(const BlendValueSupport* input) const
{
    return input->IsBoolValueSupported();
}
