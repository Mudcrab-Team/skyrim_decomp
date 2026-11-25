// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x74a4e0 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// 0x104df40 Owner104df40::Function104df40
#include "Owner104df40.h"

extern std::uint8_t globalFlagB_104df40;

Owner104df40::Owner104df40()
{
}

// guess: same compiled code as matched 0x74a4e0 apart from relocated fields; its role here is not established.
void Owner104df40::Function104df40(std::uint8_t value)
{
    globalFlagB_104df40 = value;
}
