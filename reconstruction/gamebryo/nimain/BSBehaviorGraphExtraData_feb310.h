// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBehaviorGraphExtraData: EXE_RTTI
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI STANDIN; only the destructor the function needs
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the destructor the function needs
// BSBehaviorGraphExtraData::unk18: GUESS(low); released by the BSFixedString destructor
#pragma once

class BSFixedString
{
public:
    ~BSFixedString();

    const char* data;
};

class NiExtraData
{
public:
    NiExtraData();
    virtual ~NiExtraData();

    char unk08[0x8];
    void* name;
};

class BSBehaviorGraphExtraData : public NiExtraData
{
public:
    BSBehaviorGraphExtraData();
    ~BSBehaviorGraphExtraData() override {}

    BSFixedString unk18;
    char unk20[0x8];
};
static_assert(sizeof(BSBehaviorGraphExtraData) == 0x28, "BSBehaviorGraphExtraData size from the deleting destructor");
