// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffectReferenceEffectController, GetScale, effect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffect, EffectSetting, GetBaseObject, flags, dualCastScale: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Func3_14055D150: CRASHLOGGER_PDB(59818@2026.10.24); the name GetScale is the community one for slot 3
// EffectSetting::Function14b7e0: GUESS(low); unknown predicate on the base effect
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit, shape only)
#pragma once

#include <cstdint>

class EffectSetting
{
public:
    bool Function14b7e0();  // bound: 0x14b7e0

    unsigned char pad00[0x110];  // 00
    float dualCastScale;         // 110 (data + A8)
};

class ActiveEffect
{
public:
    EffectSetting* GetBaseObject();  // bound: 0x5bb090

    unsigned char pad00[0x7C];  // 00
    std::uint32_t flags;        // 7C
};

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class ActiveEffectReferenceEffectController
{
public:
    virtual ~ActiveEffectReferenceEffectController();  // 00
    virtual void unk01();                               // 01
    virtual void unk02();                               // 02
    virtual float GetScale();                           // 03

    ActiveEffect* effect;  // 08
};
