// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x41efc0 TESObjectWEAP::GetDamageScaled
// Adapted bodies: TestBit, a one-line flag-bit helper, resembles momusdigital/f3_decomp@f5bac1b src/f3staging/f3blk_004e0000_o2.cpp:49422 (CC0-1.0); Sibling source: momusdigital/f3_decomp@f5bac1b src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "TESObjectWEAP_41efc0.h"

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

float TESObjectWEAP::GetDamageScaled()
{
    float scale = 1.0f;
    if (TestBit(data.flags2, 7)) {
        scale = data.unk1C;
    } else {
        int type = data.animationType;
        if (type >= -1 && type <= 6) {
            scale = gMeleeDamageScale;
        } else if (((type - 7) & 0xFD) == 0) {
            scale = gRangedDamageScale;
        }
    }
    return static_cast<float>(attackDamageForm.GetAttackDamage()) * scale;
}
