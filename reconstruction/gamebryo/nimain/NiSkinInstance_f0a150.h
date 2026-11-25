// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiSkinInstance: GUESS(low); the class is the placeholder owner
// FindCommonAncestor: GUESS(low); the name is made up, this pointer is unused by the body
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the parent member is declared
// parent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); member at 0x30
// pad00: GUESS(low); unrecovered storage
#pragma once

#include <cstdint>

class NiAVObject
{
public:
    std::uint8_t pad00[0x30];
    NiAVObject* parent;
};

class NiSkinInstance
{
public:
    NiAVObject* FindCommonAncestor(NiAVObject* a_first, NiAVObject* a_second);  // compared: 0xf0a150
};
