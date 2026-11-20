// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf389f0 NiCapsuleBV::CopyMembers
// 0xf38b40 NiCapsuleBV::IsSameVolume
// 0xf38b90 NiCapsuleBV::Differs
// Adapted bodies: none
#include "NiCapsuleBV_f389f0.h"

void NiCapsuleBV::CopyMembers(const NiCapsuleBV& other)
{
    unknown08 = other.unknown08;
    unknown0C = other.unknown0C;
    unknown10 = other.unknown10;
    unknown14 = other.unknown14;
    unknown18 = other.unknown18;
    unknown1C = other.unknown1C;
    unknown20 = other.unknown20;
    capsule.radius = other.capsule.radius;
    return UpdateCapsule();
}

bool NiCapsuleBV::IsSameVolume(const NiBoundingVolume& other) const
{
    return other.GetVolumeType() == 2 &&
           static_cast<const NiCapsuleBV&>(other).capsule.IsEqual(capsule);
}

bool NiCapsuleBV::Differs(const NiBoundingVolume& other) const
{
    return !Slot09(other);
}
