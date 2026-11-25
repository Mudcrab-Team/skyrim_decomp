// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the pinned listings using the cited declarations. Stamped as a twin of matched 0x30ea50 (skyrim_shared/world/TESWorldSpace_30db60): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// 0x120f00 Owner120f00::Function120f00
#include "Owner120f00.h"

// guess: same compiled code as matched 0x30ea50 apart from relocated fields; its role here is not established.
std::uint32_t Owner120f00::Function120f00() const
{
    return cellMap.capacity - cellMap.freeSlots;
}
