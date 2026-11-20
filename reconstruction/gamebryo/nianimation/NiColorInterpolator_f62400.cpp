// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf62400 NiColorInterpolator::CopyMembers
// 0xf62470 NiColorInterpolator::LoadBinary
// 0xf624f0 NiColorInterpolator::RegisterStreamables
// 0xf62540 NiColorInterpolator::SaveBinary
// 0xf626e0 NiColorInterpolator::Ctor
// 0xf628d0 NiColorInterpolator::SetPoseValue
// Adapted bodies: none
#include "NiColorInterpolator_f62400.h"

extern const NiColorA gDefaultPose;

void NiColorInterpolator::CopyMembers(NiColorInterpolator* dest) const
{
    NiKeyBasedInterpolator::CopyMembers(dest);
    dest->colorValue = colorValue;
    dest->colorData.Reset(colorData);
    dest->lastIndex = lastIndex;
}

void NiColorInterpolator::LoadBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::LoadBinary(stream);
    colorValue.LoadBinary(stream);
    colorData.Reset(static_cast<NiColorData*>(ReadStreamObjectLink(stream)));
}

bool NiColorInterpolator::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiKeyBasedInterpolator::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (colorData.pointer) {
        colorData.pointer->RegisterStreamables(stream);
    }
    return true;
}

void NiColorInterpolator::SaveBinary(NiStream& stream)
{
    NiKeyBasedInterpolator::SaveBinary(stream);
    colorValue.SaveBinary(stream);
    return stream.SaveLinkID(colorData.pointer);
}

NiColorInterpolator::NiColorInterpolator(NiColorData* keys) :
    colorValue(gDefaultPose), colorData(keys), lastIndex(0)
{

}

void NiColorInterpolator::SetPoseValue(const NiColorA& pose)
{
    colorData.Reset(nullptr);
    colorValue = pose;
}
