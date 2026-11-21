// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf84940 NiPoint3Interpolator::CopyMembers
// 0xf849c0 NiPoint3Interpolator::LoadBinary
// 0xf84c30 NiPoint3Interpolator::Ctor
// Adapted bodies: none
#include "NiPoint3Interpolator_f84940.h"

extern const NiPoint3 gDefaultPose;

void NiPoint3Interpolator::CopyMembers(NiPoint3Interpolator* dest) const
{
    NiKeyBasedInterpolator::CopyMembers(dest);
    dest->value.x = value.x;
    dest->value.y = value.y;
    dest->value.z = value.z;
    dest->data.Reset(data);
    dest->lastIndex = lastIndex;
}

void NiPoint3Interpolator::LoadBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::LoadBinary(stream);
    value.LoadBinary(stream);
    data.Reset(static_cast<NiPosData*>(ReadStreamObjectLink(stream)));
}

NiPoint3Interpolator::NiPoint3Interpolator(NiPosData* keys) :
    value{gDefaultPose.x, gDefaultPose.y, gDefaultPose.z}, data(keys), lastIndex(0)
{

}
