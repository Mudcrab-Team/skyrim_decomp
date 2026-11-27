// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x74a4e0 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// 0x153570 Owner153570::Function153570
#include "Owner153570.h"

extern std::uint8_t globalFlagB_153570;

Owner153570::Owner153570()
{
}

// guess: same compiled code as matched 0x74a4e0 apart from relocated fields; its role here is not established.
void Owner153570::Function153570(std::uint8_t value)
{
    globalFlagB_153570 = value;
}
