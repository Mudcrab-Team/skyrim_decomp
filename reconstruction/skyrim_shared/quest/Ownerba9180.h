// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x3ab120 (skyrim_shared/quest/BGSSceneAction): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Ownerba9180: GUESS(low) STANDIN
// unknown08, Unk_05, flags10, flags14, unknown98: GUESS(low) STANDIN
#pragma once
#include "BGSSceneAction.h"
#include <atomic>

class Ownerba9180
{
public:
    virtual void Unk_0B();
    virtual void Unk_10();
    virtual void ClearFlags();
    virtual void Unk_11();
    virtual void Unk_02(Ownerba9180* a_other);
    virtual bool Unk_05();

    volatile std::uint32_t unknown08;  // 08
    std::uint32_t unknown0C;  // 0C
    std::uint32_t flags10;  // 10
    unsigned char padTwin14[4];
    std::uint8_t flags14;  // 14
    std::uint8_t unknown15[0x83];  // 15
    void* unknown98;  // 98
};
static_assert(sizeof(Ownerba9180) == 0xa8, "Ownerba9180 size");
