// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); body written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xf0db60 NiSkinData::RegisterStreamables
#include "NiSkinData.h"

bool NiSkinData::RegisterStreamables(NiStream& a_stream)
{
    return NiObject::RegisterStreamables(a_stream) != false;
}
