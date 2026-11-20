// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfbfc30 BSPSysInheritVelocityModifier::LinkObject
// Adapted bodies: none
#include "BSPSysInheritVelocityModifier.h"

void BSPSysInheritVelocityModifier::LinkObject(NiStream& stream)
{
    NiPSysModifier::LinkObject(stream);
    linkedObject = stream.ReadLinkID();
}
