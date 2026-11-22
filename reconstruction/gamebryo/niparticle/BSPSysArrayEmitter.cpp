// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing and community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xfe13f0 BSPSysArrayEmitter::Functionfe13f0
// 0xfe0f00 BSPSysArrayEmitter::Functionfe0f00
// Adapted bodies: none
// Functionfe13f0: GUESS(low)
// Functionfe0f00: GUESS(low)
// ForwardValue, TailTarget, unk70: GUESS(low)
// BSPSysArrayEmitter, PostLinkObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PostLinkBase, PostLinkReferences: GUESS(low)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "BSPSysArrayEmitter.h"

void BSPSysArrayEmitter::Functionfe13f0(void* a1, void* a2, void* a3)
{
    return TailTarget(a2, a3);
}

void BSPSysArrayEmitter::Functionfe0f00(void* a_value)
{
    unk70 = a_value;
    return ForwardValue(a_value);
}

void BSPSysArrayEmitter::PostLinkObject(NiStream& stream)
{
    PostLinkBase(stream);
    return PostLinkReferences(stream);
}
