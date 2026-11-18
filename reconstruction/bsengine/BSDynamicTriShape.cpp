// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); bodies written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0xefd460 BSDynamicTriShape::IsEqual
// 0x26d490 BSDynamicTriShape::AsDynamicTriShape
#include "BSDynamicTriShape.h"

bool BSDynamicTriShape::IsEqual(NiObject* a_object)
{
    return false;
}

BSDynamicTriShape* BSDynamicTriShape::AsDynamicTriShape()
{
    return this;
}
