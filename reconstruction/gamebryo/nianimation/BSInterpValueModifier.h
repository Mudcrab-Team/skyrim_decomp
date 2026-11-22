// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction; body written from the listing.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSInterpValueModifier: EXE_RTTI
// Unk_0A: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionbb8310, padding, member: GUESS(low)
#pragma once

#include <cstdint>

class BSInterpValueModifier
{
public:
    virtual std::uint8_t Unk_0A() const;
    void Functionbb8310();

    std::uint8_t padding[0x58];  // 08
    std::uint32_t member;        // 60
};
