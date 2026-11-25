// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xce4260 (bscore/BSThread): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionaad250, Owneraad250: GUESS(low) STANDIN
// unknown08, field30: GUESS(low) STANDIN
#pragma once
#include "BSThread.h"

class Owneraad250
{
public:
    virtual void Unk_02();
    virtual std::uint32_t Unk_01();
    void Functionaad250();

    std::uint8_t unknown08[0x8];  // 08
    void* field30;  // 30
    std::uint8_t unknown38[0x18];  // 38
};
static_assert(sizeof(Owneraad250) == 0x30, "Owneraad250 size");
