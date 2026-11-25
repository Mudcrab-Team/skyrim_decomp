// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0x159af80 (skyrim_shared/saveload/BSSaveDataSystemUtility): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Owner14d6de0: GUESS(low) STANDIN
// unknown08, Unk_05, Unk_07, Unk_08: GUESS(low) STANDIN
#pragma once
#include "BSSaveDataSystemUtility.h"

class Owner14d6de0
{
public:
    virtual std::uint64_t* Unk_0B(std::uint64_t* a_out);
    virtual std::uint32_t Unk_0A(void* a_obj);
    virtual void Unk_05();
    virtual bool Unk_07();
    virtual bool Unk_08();

    std::uint8_t unknown08[0x220];  // 08
};
static_assert(sizeof(Owner14d6de0) == 0x228, "Owner14d6de0 size");
