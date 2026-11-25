// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESShout, Variation, TESWordOfPower, SpellItem, variations, word, spell, recoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESShout::Function387e20: GUESS(low); placeholder pending name evidence.
// opaquePrefix: GUESS(low) STANDIN; unaccessed TESForm and component bases.
#pragma once
#include <cstddef>
#include <cstdint>

class TESWordOfPower;
class SpellItem;
class TESShout
{
public:
    struct Variation
    {
        TESWordOfPower* word;
        SpellItem* spell;
        float recoveryTime;
    };
    std::uint32_t Function387e20() const;
    std::uint8_t opaquePrefix[0x60];
    Variation variations[3];
};
static_assert(sizeof(TESShout::Variation) == 0x18, "community layout");
static_assert(offsetof(TESShout, variations) == 0x60, "community layout");
