// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfe1410 BSPSysArrayEmitter::PostLinkObject
// Adapted bodies: none
#include "BSPSysArrayEmitter.h"

void BSPSysArrayEmitter::PostLinkObject(NiStream& stream)
{
    PostLinkBase(stream);
    return PostLinkReferences(stream);
}
