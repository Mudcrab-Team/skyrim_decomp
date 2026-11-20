// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf2dae0 NiBoxBV::LoadBinary
// 0xf2db20 NiBoxBV::SaveBinary
// 0xf2e040 NiBoxBV::IsSameVolume
// 0xf2e090 NiBoxBV::Differs
// Adapted bodies: none
#include "NiBoxBV_f2dae0.h"

void NiBoxBV::LoadBinary(NiStream& stream)
{
    NiBoundingVolume::LoadBinary(stream);
    return box.LoadBinary(stream);
}

void NiBoxBV::SaveBinary(NiStream& stream)
{
    NiBoundingVolume::SaveBinary(stream);
    return box.SaveBinary(stream);
}

bool NiBoxBV::IsSameVolume(const NiBoundingVolume& other) const
{
    return other.GetVolumeType() == 1 &&
           static_cast<const NiBoxBV&>(other).box.IsEqual(box);
}

bool NiBoxBV::Differs(const NiBoundingVolume& other) const
{
    return !Slot09(other);
}
