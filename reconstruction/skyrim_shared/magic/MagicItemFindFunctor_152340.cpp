// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x152340 MagicItemFindFunctor::operator
#include "MagicItemFindFunctor_152340.h"

// Counts effects until one matches, then records the index of the match and stops.
BSContainer::ForEachResult MagicItemFindFunctor::operator()(Effect* a_effect)
{
    const bool   matched = MatchCondition(a_effect);
    std::int32_t current = indexCount;
    auto         result = BSContainer::ForEachResult::kStop;
    if (matched) {
        index = current;
    } else {
        ++current;
        result = BSContainer::ForEachResult::kContinue;
        indexCount = current;
    }
    return result;
}
