// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x757410 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// 0x9ad150 Owner9ad150::Function9ad150
#include "Owner9ad150.h"

extern bool globalFlagC_9ad150;

Owner9ad150::Owner9ad150()
{
}

// guess: same compiled code as matched 0x757410 apart from relocated fields; its role here is not established.
void Owner9ad150::Function9ad150()
{
    globalFlagC_9ad150 = false;
}
