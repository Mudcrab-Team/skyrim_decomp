// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSAcousticSpace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// BGSAcousticSpace::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class BGSAcousticSpace : public TESBoundObject
{
public:
    virtual void InitializeData();  // compared: 0x315990

    // unknown20: GUESS(low)
    std::uint8_t unknown20[0x10];  // 20
    // unknown30: GUESS(low)
    std::uint64_t unknown30;  // 30
    // unknown38: GUESS(low)
    std::uint64_t unknown38;  // 38
    // unknown40: GUESS(low)
    std::uint64_t unknown40;  // 40
};
