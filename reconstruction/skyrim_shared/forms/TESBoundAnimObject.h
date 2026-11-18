// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESBoundAnimObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESBoundAnimObject::~TESBoundAnimObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject::~TESBoundObject: GUESS(low)
// unknown20: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
    virtual ~TESBoundObject();
};

class TESBoundAnimObject : public TESBoundObject
{
public:
    TESBoundAnimObject();
    virtual ~TESBoundAnimObject() {}  // compared: 0x279140 (scalar deleting destructor)

    std::uint8_t unknown20[0x10];  // 20
};
static_assert(sizeof(TESBoundAnimObject) == 0x30, "TESBoundAnimObject size");
