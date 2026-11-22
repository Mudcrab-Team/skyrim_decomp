// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x387da0 TESShout::GetShoutLevel
// Adapted bodies: none
#include "TESShout_387da0.h"

int TESShout::GetShoutLevel()
{
    int i = 0;
    for (; i < 3; ++i) {
        if (variations[i].word && !variations[i].word->GetKnown()) {
            break;
        }
    }
    return i - 1;
}
