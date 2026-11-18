// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESObjectWEAP::GetPlayable, TESObjectWEAP::GetObjectTypeName, TESObjectWEAP::GetDescriptionOwnerFile, TESObjectWEAP::~TESObjectWEAP: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk19D, unk19E, unknown20, unknown19F, unknown208, unknown210: GUESS(low)
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

class TESObjectWEAP : public TESBoundObject
{
public:
    TESObjectWEAP();
    virtual bool GetPlayable() const;  // compared: 0x28e810
    virtual const char* GetObjectTypeName() const;  // compared: 0x28e7f0
    virtual TESFile* GetDescriptionOwnerFile() const;  // compared: 0x28e7b0
    virtual ~TESObjectWEAP();  // compared: 0x28e500 (scalar deleting destructor)

    // Members read by the compared bodies, split out of the padding; the size assert keeps the layout.
    std::uint8_t unknown20[0x17D];  // 20
    std::int8_t unk19D;             // 19D, signed index into the name table
    std::uint8_t unk19E;            // 19E, flags; bit 7 is tested
    std::uint8_t unknown19F[0x69];  // 19F
    TESForm* unknown208;            // 208
    std::uint8_t unknown210[0x10];  // 210
};
static_assert(sizeof(TESObjectWEAP) == 0x220, "TESObjectWEAP size");
