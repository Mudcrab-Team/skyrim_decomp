// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESSound::Clone3D, TESSound::InitializeData, TESSound::SetFormEditorID, TESSound::~TESSound: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown30: GUESS(low)
// NiAVObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "../forms/TESForm.h"

class NiAVObject;

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class TESBoundAnimObject : public TESBoundObject
{
public:
};

class TESSound : public TESBoundAnimObject
{
public:
    TESSound();
    virtual NiAVObject* Clone3D(TESObjectREFR* a_ref);  // compared: 0x388860
    virtual void InitializeData();  // compared: 0x388880
    virtual bool SetFormEditorID(const char* a_str);  // compared: 0x388620
    virtual ~TESSound();  // compared: 0x3888d0 (scalar deleting destructor)

    std::uint8_t unknown20[0x10];  // 20
    void* unknown30;  // 30
};
