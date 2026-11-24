// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBoneLODExtraData: EXE_RTTI
// NiExtraData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI STANDIN; only the destructor the function needs
// BSBoneLODExtraDataUnk18, BSBoneLODExtraData::unk18: GUESS(low); a member with its own out-of-line destructor
#pragma once

class BSBoneLODExtraDataUnk18
{
public:
    ~BSBoneLODExtraDataUnk18();

    char unk00[0x18];
};

class NiExtraData
{
public:
    NiExtraData();
    virtual ~NiExtraData();

    char unk08[0x8];
    void* name;
};

class BSBoneLODExtraData : public NiExtraData
{
public:
    BSBoneLODExtraData();
    ~BSBoneLODExtraData() override {}

    BSBoneLODExtraDataUnk18 unk18;
};
static_assert(sizeof(BSBoneLODExtraData) == 0x30, "BSBoneLODExtraData size from the deleting destructor");
