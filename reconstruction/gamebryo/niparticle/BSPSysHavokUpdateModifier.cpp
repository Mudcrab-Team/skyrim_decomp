// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf9d960 BSPSysHavokUpdateModifier::LoadBinary
// 0xf9da40 BSPSysHavokUpdateModifier::SaveBinary
// 0xf9df50 BSPSysHavokUpdateModifier::PostLinkObject
// Adapted bodies: none
#include "BSPSysHavokUpdateModifier.h"

void BSPSysHavokUpdateModifier::LoadBinary(NiStream& stream)
{
    NiPSysMeshUpdateModifier::LoadBinary(stream);
    return stream.LoadLinkID();
}

void BSPSysHavokUpdateModifier::SaveBinary(NiStream& stream)
{
    NiPSysMeshUpdateModifier::SaveBinary(stream);
    return stream.SaveLinkID(linkedModifier);
}

void BSPSysHavokUpdateModifier::PostLinkObject(NiStream& stream)
{
    NiPSysMeshUpdateModifier::PostLinkBase(stream);
    if (linkedModifier) {
        return linkedModifier->SetSystemPointer(target);
    }
}
