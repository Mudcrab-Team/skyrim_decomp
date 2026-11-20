// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf39d50 NiHalfSpaceBV::LoadBinary
// 0xf39d90 NiHalfSpaceBV::SaveBinary
// 0xf39f40 NiHalfSpaceBV::IsSamePlane
// 0xf3a070 NiHalfSpaceBV::Differs
// Adapted bodies: none
#include "NiHalfSpaceBV_f39d50.h"

void NiHalfSpaceBV::LoadBinary(NiStream& stream)
{
    NiBoundingVolume::LoadBinary(stream);
    plane.LoadBinary(stream);
    return point.LoadBinary(stream);
}

void NiHalfSpaceBV::SaveBinary(NiStream& stream)
{
    NiBoundingVolume::SaveBinary(stream);
    plane.SaveBinary(stream);
    return point.SaveBinary(stream);
}

bool NiHalfSpaceBV::IsSamePlane(const NiHalfSpaceBV& other) const
{
    return ComparePlane(other.plane);
}

bool NiHalfSpaceBV::Differs(const NiBoundingVolume& other) const
{
    return !Slot09(other);
}
