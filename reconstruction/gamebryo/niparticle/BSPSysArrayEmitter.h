// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysArrayEmitter, PostLinkObject: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PostLinkBase, PostLinkReferences: GUESS(low)
// NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiStream;

class BSPSysArrayEmitter
{
public:
    void PostLinkObject(NiStream& stream);

private:
    void PostLinkBase(NiStream& stream);
    void PostLinkReferences(NiStream& stream);
};
