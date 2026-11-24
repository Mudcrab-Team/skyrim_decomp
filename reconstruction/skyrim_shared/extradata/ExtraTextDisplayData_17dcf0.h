// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData, ExtraTextDisplayData, ExtraTextDisplayData::displayName, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; only the destructor the function needs
#pragma once

class BSFixedString
{
public:
    ~BSFixedString();

    const char* data;
};

class BSExtraData
{
public:
    BSExtraData();
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class ExtraTextDisplayData : public BSExtraData
{
public:
    ExtraTextDisplayData();

    BSFixedString displayName;
    char unk18[0x20];
};
static_assert(sizeof(ExtraTextDisplayData) == 0x38, "ExtraTextDisplayData size from the deleting destructor");
