// Source exposure: mixed (pinned-image analysis; community and permitted sibling declarations).
// Code origin: original; handwritten from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x387e20 TESShout::Function387e20
// Adapted bodies: none.
// Cookbook: 44
#include "TESShout_387e20.h"

// Returns the highest variation with both a word and a spell.
std::uint32_t TESShout::Function387e20() const
{
    std::uint32_t index = 2;
    std::int64_t remaining = index;
    const Variation* variation = &variations[2];
    std::int64_t previous;
    do {
        previous = remaining;
        if (variation->word && variation->spell)
            return index;
        --index;
        --remaining;
        --variation;
    } while (previous > 0);
    return 0;
}
