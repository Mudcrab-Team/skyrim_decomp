// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf74630 NiBlendQuaternionInterpolator::CopyMembers
// 0xf74660 NiBlendQuaternionInterpolator::LoadBinary
// 0xf746c0 NiBlendQuaternionInterpolator::SaveBinary
// 0xf74990 NiBlendQuaternionInterpolator::SupportsBlendValue
// 0xf74da0 NiBlendQuaternionInterpolator::dtor
#include "NiBlendQuaternionInterpolator_f74630.h"

// LoadBlendValue: GUESS(low); reads the interpolated value from the stream.
void LoadBlendValue(NiQuaternion& value, NiStream& stream);

// SaveBlendValue: GUESS(low); writes the interpolated value to the stream.
void SaveBlendValue(const NiQuaternion& value, NiStream& stream);

// An out-of-line constructor emits the compiler-generated deleting destructor.
NiBlendQuaternionInterpolator::NiBlendQuaternionInterpolator() = default;

void NiBlendQuaternionInterpolator::CopyMembers(NiBlendQuaternionInterpolator* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
}

void NiBlendQuaternionInterpolator::LoadBinary(NiStream& stream)
{
    NiBlendInterpolator::LoadBinary(stream);
    return LoadBlendValue(value, stream);
}

void NiBlendQuaternionInterpolator::SaveBinary(NiStream& stream)
{
    NiBlendInterpolator::SaveBinary(stream);
    return SaveBlendValue(value, stream);
}

bool NiBlendQuaternionInterpolator::SupportsBlendValue(const BlendValueSupport* input) const
{
    return input->IsQuaternionValueSupported();
}
