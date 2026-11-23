// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x387e20 TESShout::FindLastFilledVariation
// Adapted bodies: none
#include "TESShout_387e20.h"

int32_t TESShout::FindLastFilledVariation()
{
    int32_t result = 2;
    int64_t i = 2;
    const ShoutVariation* variation = &variations[2];
    int64_t remaining;
    do {
        remaining = i;
        if (variation->word && variation->spell) {
            return result;
        }
        --result;
        --i;
        --variation;
    } while (remaining > 0);
    return 0;
}
