// Source exposure: mixed (labelled community declarations and the pinned image listing).
// Code origin: original typed reconstruction; layouts retained or adapted from the labelled declaration sources.
// Adapted bodies: none
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// New function names, signatures and helper names: GUESS(low); unknown semantics remain unnamed.
// 0x1648b0 FindOutfitExtra
// 0x171100 ExtraDataList::GetFactionChanges
#include "ExtraDataList_1648b0.h"

// Find the outfit-item extra data.
OutfitExtra* FindOutfitExtra(ExtraDataList* a_list)
{
    constexpr std::uint32_t kOutfitItem = 0x8E;
    return static_cast<OutfitExtra*>(a_list->GetByType(kOutfitItem));
}

// Find the faction-change extra data.
ExtraFactionChanges* ExtraDataList::GetFactionChanges()
{
    constexpr std::uint32_t kFactionChanges = 0x5B;
    return static_cast<ExtraFactionChanges*>(GetByType(kFactionChanges));
}
