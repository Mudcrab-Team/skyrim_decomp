// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfc0f20 NiPSysFieldModifier::LinkObject
// 0xfc12e0 NiPSysFieldModifier::dtor
// Adapted bodies: none
#include "NiPSysFieldModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysFieldModifier::NiPSysFieldModifier() = default;

void NiPSysFieldModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
