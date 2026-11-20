// Source exposure: mixed (names and declarations from community headers; base classes, sizes and the compared functions from the pinned image).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCONT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject, TESBoundAnimObject: STANDIN EXE_RTTI
// TESObjectCONT::InitializeData, TESObjectCONT::InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20, unkB9, unknownBA, unkC0, unkC8: GUESS(low)
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

class TESBoundAnimObject : public TESBoundObject
{
public:
};

class TESObjectCONT : public TESBoundAnimObject
{
public:
    virtual void InitializeData();  // compared: 0x281530
    void InitItemImpl() override;  // compared: 0x281a30

    // Members written by the compared body, split out of the padding; the total size is not known from the listing.
    std::uint8_t unknown20[0x99];  // 20
    std::uint8_t unkB9;            // B9
    std::uint8_t unknownBA[0x6];   // BA
    std::uint64_t unkC0;           // C0
    std::uint64_t unkC8;           // C8
};
