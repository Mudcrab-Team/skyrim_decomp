// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSIdleMarker: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// BGSIdleMarker::GetIgnoredBySandbox: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
};

class BGSIdleMarker : public TESBoundObject
{
public:
    virtual bool GetIgnoredBySandbox() const;  // compared: 0x391b80

    // unknown20: GUESS(low)
    std::uint8_t unknown20[0x40];  // 20
    // unknown60: GUESS(low)
    std::uint8_t unknown60;  // 60
};
