// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, bases, members and declarations
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0x396b40 BGSPerk::InitializeData
#include "BGSPerk.h"

void BGSPerk::InitializeData()
{
    data.trait = false;
    data.level = 0;
    data.numRanks = 1;
    data.playable = true;
    data.hidden = false;
    nextPerk = nullptr;
}
