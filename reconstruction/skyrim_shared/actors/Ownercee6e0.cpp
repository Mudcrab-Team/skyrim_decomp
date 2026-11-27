// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x74a4e0 (skyrim_shared/actors/PlayerCharacter_69f950): source copied, names replaced by placeholders.
// 0xcee6e0 Ownercee6e0::Functioncee6e0
#include "Ownercee6e0.h"

extern std::uint8_t globalFlagB_cee6e0;

Ownercee6e0::Ownercee6e0()
{
}

// guess: same compiled code as matched 0x74a4e0 apart from relocated fields; its role here is not established.
void Ownercee6e0::Functioncee6e0(std::uint8_t value)
{
    globalFlagB_cee6e0 = value;
}
