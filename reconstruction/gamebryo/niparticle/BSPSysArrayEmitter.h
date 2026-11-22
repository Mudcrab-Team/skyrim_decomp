// Source exposure: mixed (pinned image and cited public declarations).
// 0xfe13f0 compared function
// 0xfe0f00 compared function
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysArrayEmitter, PostLinkObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PostLinkBase, PostLinkReferences: GUESS(low)
// Functionfe0f00, Functionfe13f0: GUESS(low)
// ForwardValue, TailTarget, unk70: GUESS(low)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiStream;

class BSPSysArrayEmitter
{
public:
    void PostLinkObject(NiStream& stream);
    void Functionfe0f00(void* a_value);
    void Functionfe13f0(void* a1, void* a2, void* a3);

private:
    void PostLinkBase(NiStream& stream);
    void PostLinkReferences(NiStream& stream);
    void ForwardValue(void* a_value);
    void TailTarget(void* a_value, void* a_value2);

    char _pad_0[0x70];
    void* unk70;
};
