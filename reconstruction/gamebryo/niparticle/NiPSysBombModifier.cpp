// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfa6e10 NiPSysBombModifier::LinkObject
// 0xfa7c30 NiPSysBombModifier::dtor
// Adapted bodies: none
#include "NiPSysBombModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysBombModifier::NiPSysBombModifier() = default;

void NiPSysBombModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
