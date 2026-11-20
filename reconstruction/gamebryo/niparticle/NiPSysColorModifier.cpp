// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfaa2d0 NiPSysColorModifier::LoadBinary
// 0xfaa300 NiPSysColorModifier::LinkObject
// 0xfaa390 NiPSysColorModifier::SaveBinary
// Adapted bodies: none
#include "NiPSysColorModifier.h"

void NiPSysColorModifier::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    return stream.LoadLinkID();
}

void NiPSysColorModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    return SetLinkedObject(stream.ReadLinkID());
}

void NiPSysColorModifier::SaveBinary(NiStream& stream)
{
    NiPSysModifier::SaveBinary(stream);
    return stream.SaveLinkID(linkedObject);
}
