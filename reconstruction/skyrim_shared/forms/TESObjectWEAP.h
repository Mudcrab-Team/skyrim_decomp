// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// member offsets from the listing of the pinned image).
// Code origin: community declarations; stand-in bases and guessed members written from the listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESObjectWEAP::GetPlayable, TESObjectWEAP::GetObjectTypeName, TESObjectWEAP::GetDescriptionOwnerFile, TESObjectWEAP::~TESObjectWEAP: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSImpactDataSet, impactDataSet: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the pointer at 0x1F8
// unk19D, unk19E, unknown20, unknown19F, unknown170, unknown200, unknown208, unknown210, Function28c020, Function28c260: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class BGSImpactDataSet;

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
    void* Function28c020();  // compared: 0x28c020
    std::uint32_t Function28c260();  // compared: 0x28c260

    // RangedData, RangedData::numProjectiles, rangedData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    struct RangedData
    {
        std::uint8_t unk00[0x18];     // 00
        std::int8_t  numProjectiles;  // 18
        std::uint8_t pad19[3];        // 19
    };

    // GetNumProjectiles: GUESS(low)
    std::uint8_t GetNumProjectiles() const;

    // Members read by the compared bodies, split out of the padding; the size assert keeps the layout.
    std::uint8_t unknown20[0x148];  // 20
    RangedData* rangedData;         // 168
    std::uint8_t unknown170[0x2D];  // 170
    std::int8_t unk19D;             // 19D, signed index into the name table
    std::uint8_t unk19E;            // 19E, flags; bit 7 is tested
    std::uint8_t unknown19F[0x59];  // 19F
    BGSImpactDataSet* impactDataSet;  // 1F8
    std::uint8_t unknown200[0x8];   // 200
    TESForm* unknown208;            // 208
    std::uint8_t unknown210[0x10];  // 210
};
static_assert(sizeof(TESObjectWEAP) == 0x220, "TESObjectWEAP size");
