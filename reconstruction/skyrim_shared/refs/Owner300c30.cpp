// Source exposure: mixed
// Code origin: Stamped as a twin of matched 0x300c90 (skyrim_shared/refs/TESObjectREFR_2fd720): source copied, names replaced by placeholders.
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_ExtraData.cpp:378
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR_Animation.cpp:71
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x300c30 Owner300c30::Function300c30
#include "Owner300c30.h"

// guess: same compiled code as matched 0x300c90 apart from relocated fields; its role here is not established.
void Owner300c30::Function300c30(ActorCause* cause) { extraList.SetActorCauseExtra(cause); AddChange(0x80000000u); }
