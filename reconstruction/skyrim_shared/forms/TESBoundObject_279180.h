// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESBoundObject, TESObject, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESForm: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class TESForm
{
public:
    TESForm();
    virtual ~TESForm();
};

class TESObject : public TESForm
{
public:
    TESObject();
    ~TESObject() override {}
};

class TESBoundObject : public TESObject
{
public:
    TESBoundObject();

    char unk08[0x28];
};
static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject size from the deleting destructor");
