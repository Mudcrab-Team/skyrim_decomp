// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectWEAP, TESObjectWEAP::Data, TESObjectWEAP::Data::unk1C, TESObjectWEAP::Data::flags2, TESObjectWEAP::Data::animationType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectWEAP::GetDamageScaled: GUESS(low); the class is the placeholder owner, the PDB-derived placeholder is sub_1403BE4E0
// TESAttackDamageForm, TESAttackDamageForm::GetAttackDamage: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 04, slots 00 to 03 are placeholders
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// gMeleeDamageScale, gRangedDamageScale: GUESS(low); two float globals read by the function
#pragma once

#include <cstdint>
#include <cstddef>

extern float gMeleeDamageScale;
extern float gRangedDamageScale;

class TESAttackDamageForm
{
public:
    virtual ~TESAttackDamageForm();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual std::uint16_t GetAttackDamage() const;
    std::uint16_t attackDamage;
};

class TESObjectWEAP
{
public:
    struct Data
    {
        std::uint8_t pad00[0x1C];
        float unk1C;
        std::uint8_t pad20[0x10];
        std::uint16_t flags2;
        std::uint8_t pad32[3];
        std::int8_t animationType;
        std::uint8_t pad36[2];
    };
    static_assert(sizeof(Data) == 0x38, "Data size");

    float GetDamageScaled();  // compared: 0x41efc0

    std::uint8_t pad000[0xC0];
    TESAttackDamageForm attackDamageForm;
    std::uint8_t pad0D0[0x168 - 0xD0];
    Data data;
};
static_assert(offsetof(TESObjectWEAP, data) == 0x168, "data offset");
