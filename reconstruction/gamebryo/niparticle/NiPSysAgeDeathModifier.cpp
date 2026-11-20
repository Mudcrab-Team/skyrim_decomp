// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa6570 NiPSysAgeDeathModifier::LinkObject
// 0xfa6b30 NiPSysAgeDeathModifier::dtor
// Adapted bodies: none
#include "NiPSysAgeDeathModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysAgeDeathModifier::NiPSysAgeDeathModifier() = default;

void NiPSysAgeDeathModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
