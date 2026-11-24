// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItemFindFunctor, MagicItemTraversalFunctor, operator(), MatchCondition, indexCount, Effect, ForEachResult, kStop, kContinue: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// index: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); a MagicItemTraversalFunctor member, declared here instead of the base class
#pragma once

#include <cstdint>
#include <cstddef>

struct Effect;

namespace BSContainer
{
    enum class ForEachResult
    {
        kStop = 0,
        kContinue = 1
    };
}

class MagicItemFindFunctor
{
public:
    virtual ~MagicItemFindFunctor();                                          // 00
    virtual BSContainer::ForEachResult operator()(Effect* a_effect);         // 01, compared: 0x152340
    virtual bool MatchCondition(Effect* a_effect) = 0;                       // 02

    std::uint32_t index;       // 08
    std::uint32_t pad0C;       // 0C
    std::int32_t  indexCount;  // 10
    std::uint32_t pad14;       // 14
};
static_assert(sizeof(MagicItemFindFunctor) == 0x18, "MagicItemFindFunctor layout differs from the community header");
