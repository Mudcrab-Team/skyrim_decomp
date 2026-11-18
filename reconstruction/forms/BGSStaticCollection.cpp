// Code origin: original drafting by Hinkiii with claude-sonnet-5-5 from a local listing of the pinned image; names, bases, members and declarations
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none.
// 0x266b20 BGSStaticCollection::ClearData
#include "BGSStaticCollection.h"

void BGSStaticCollection::ClearData()
{
    MemoryContextScope scope(0x65);
    TESBoundObject::ClearData();
}
