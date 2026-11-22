// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x240230 BGSActionData::Function240230
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
#include "BGSActionData.h"
#include <new>

void BGSActionData::Function240230()
{
    new (this) BGSActionData;
}

// Process: the target returns false.
bool BGSActionData::Process()
{
    return false;
}
