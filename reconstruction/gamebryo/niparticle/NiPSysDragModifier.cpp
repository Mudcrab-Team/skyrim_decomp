// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfac8d0 NiPSysDragModifier::LinkObject
// 0xfad2e0 NiPSysDragModifier::dtor
// Adapted bodies: none
#include "NiPSysDragModifier.h"

// Emit the virtual deleting destructor with the class constructor.
NiPSysDragModifier::NiPSysDragModifier() = default;

void NiPSysDragModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
