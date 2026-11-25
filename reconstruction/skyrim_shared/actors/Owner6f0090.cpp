// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x757410 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// 0x6f0090 Owner6f0090::Function6f0090
#include "Owner6f0090.h"

extern bool globalFlagC_6f0090;

Owner6f0090::Owner6f0090()
{
}

// guess: same compiled code as matched 0x757410 apart from relocated fields; its role here is not established.
void Owner6f0090::Function6f0090()
{
    globalFlagC_6f0090 = false;
}
