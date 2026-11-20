// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf732a0 NiBlendColorInterpolator::CopyMembers
// 0xf73380 NiBlendColorInterpolator::SaveBinary
// 0xf73640 NiBlendColorInterpolator::SupportsBlendValue
// 0xf73960 NiBlendColorInterpolator::dtor
#include "NiBlendColorInterpolator_f732a0.h"

// SaveBlendValue: GUESS(low); writes the interpolated value to the stream.
void SaveBlendValue(const NiColorA& value, NiStream& stream);

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiBlendColorInterpolator::NiBlendColorInterpolator() = default;

void NiBlendColorInterpolator::CopyMembers(NiBlendColorInterpolator* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
    dest->valid = valid;
}

void NiBlendColorInterpolator::SaveBinary(NiStream& stream)
{
    NiBlendInterpolator::SaveBinary(stream);
    return SaveBlendValue(value, stream);
}

bool NiBlendColorInterpolator::SupportsBlendValue(const BlendValueSupport* input) const
{
    return input->IsColorAValueSupported();
}
