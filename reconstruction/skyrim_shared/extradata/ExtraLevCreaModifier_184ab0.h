// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraLevCreaModifier, LEV_CREA_MODIFIER, modifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraLevCreaModifier::Function184ab0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// LEV_CREA_MODIFIER, kEasy, kMedium, kHard, kVeryHard, kNone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class LEV_CREA_MODIFIER : std::uint32_t
{
    kEasy = 0,
    kMedium = 1,
    kHard = 2,
    kVeryHard = 3,
    kNone = 4
};

// ExtraLevCreaModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSExtraData base as padding
class ExtraLevCreaModifier
{
public:
    // compared: 0x184ab0; maps the stored modifier to a small index, -1 when unknown
    int Function184ab0();

    std::uint8_t unk00[0x10];
    LEV_CREA_MODIFIER modifier;  // 10
    std::uint32_t pad14;         // 14
};
static_assert(offsetof(ExtraLevCreaModifier, modifier) == 0x10, "modifier offset");
