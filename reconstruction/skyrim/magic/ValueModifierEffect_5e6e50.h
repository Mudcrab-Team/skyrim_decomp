// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ValueModifierEffect, ClearTargetImpl, ShouldModifyOnFinish, Finish, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Func18_140567270: CRASHLOGGER_PDB(59818@2026.10.24); the unit uses the community name for the override
// ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit, shape only)
#pragma once

#include <cstdint>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class ActiveEffect
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
    virtual void ClearTargetImpl();  // 12
    virtual ~ActiveEffect();         // 13
    virtual void unk14();            // 14
    virtual void Finish();           // 15
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();

    unsigned char pad08[0x74];  // 08
    std::uint32_t flags;        // 7C
};

class ValueModifierEffect : public ActiveEffect
{
public:
    ~ValueModifierEffect() override;  // 13
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual bool ShouldModifyOnFinish() const;  // 1E

    void ClearTargetImpl() override;  // 12 (compared: 0x5e6e50)
};
