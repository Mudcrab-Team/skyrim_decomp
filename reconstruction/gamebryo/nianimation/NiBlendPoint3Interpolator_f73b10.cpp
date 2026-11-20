// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build.
// 0xf73b10 NiBlendPoint3Interpolator::CopyMembers
// 0xf73be0 NiBlendPoint3Interpolator::SaveBinary
// 0xf73c20 NiBlendPoint3Interpolator::IsEqual
// 0xf740f0 NiBlendPoint3Interpolator::SupportsBlendValue
// 0xf744b0 NiBlendPoint3Interpolator::dtor
#include "NiBlendPoint3Interpolator_f73b10.h"

// SaveBlendValue: GUESS(low); writes the interpolated value to the stream.
void SaveBlendValue(const NiPoint3& value, NiStream& stream);

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiBlendPoint3Interpolator::NiBlendPoint3Interpolator() = default;

void NiBlendPoint3Interpolator::CopyMembers(NiBlendPoint3Interpolator* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value.x = value.x;
    dest->value.y = value.y;
    dest->value.z = value.z;
    dest->valid = valid;
}

void NiBlendPoint3Interpolator::SaveBinary(NiStream& stream)
{
    NiBlendInterpolator::SaveBinary(stream);
    return SaveBlendValue(value, stream);
}

bool NiBlendPoint3Interpolator::IsEqual(NiObject* other)
{
    if (!NiBlendInterpolator::IsEqual(other)) {
        return false;
    }
    const auto* blend = static_cast<const NiBlendPoint3Interpolator*>(other);
    if (value.x != blend->value.x || value.y != blend->value.y || value.z != blend->value.z) {
        return false;
    }
    return true;
}

bool NiBlendPoint3Interpolator::SupportsBlendValue(const BlendValueSupport* input) const
{
    return input->IsPoint3ValueSupported();
}
