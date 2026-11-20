// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf85490 NiQuaternionInterpolator::CopyMembers
// 0xf85500 NiQuaternionInterpolator::LoadBinary
// 0xf85770 NiQuaternionInterpolator::Ctor
// Adapted bodies: none
#include "NiQuaternionInterpolator_f85490.h"

extern const NiQuaternion gDefaultPose;

void NiQuaternionInterpolator::CopyMembers(NiQuaternionInterpolator* dest) const
{
    NiKeyBasedInterpolator::CopyMembers(dest);
    dest->value = value;
    dest->data.Reset(data);
    dest->lastIndex = lastIndex;
}

void NiQuaternionInterpolator::LoadBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::LoadBinary(stream);
    value.LoadBinary(stream);
    data.Reset(static_cast<NiRotData*>(ReadStreamObjectLink(stream)));
}

NiQuaternionInterpolator::NiQuaternionInterpolator(NiRotData* keys) :
    value(gDefaultPose), data(keys), lastIndex(0)
{

}
