// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TestBit from momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// TESTopicInfo, TESFormOwner, TESFormOwner::SetAltered, TestBit: GUESS(low)
// TESTopicInfo::SetAltered: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESForm, TESForm::SetAltered, TESForm::formFlags: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); minimal stand-in, no vtable beyond the first slot
#pragma once

#include <cstdint>
#include <cstddef>

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(uint32_t a_flags, uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class TESFormOwner
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void SetAltered(bool a_set);  // slot 0x24
};

class TESForm
{
public:
    virtual ~TESForm();
    uint8_t unk08[0x8];
    uint32_t formFlags;
    uint8_t unk14[0xC];
    TESFormOwner* owner;

    void SetAltered(bool a_set);
};

class TESTopicInfo : public TESForm
{
public:
    void SetAltered(bool a_set);  // compared: 0x3f2490
};
