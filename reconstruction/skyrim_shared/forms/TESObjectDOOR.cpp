// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); body written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x282a30 TESObjectDOOR::InitializeData
// 0x2831c0 TESObjectDOOR::IsSliding
// TESObjectDOOR::IsSliding: GUESS(low)
#include "TESObjectDOOR.h"

bool TESObjectDOOR::IsSliding() const
{
    return (flags & kSliding) != 0;
}

void TESObjectDOOR::InitializeData()
{
    openSound = nullptr;
    closeSound = nullptr;
    loopSound = nullptr;
    flags = 0;
}
