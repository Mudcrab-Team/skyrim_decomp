// Code origin: GetManagerHandlesSaveLoad, GetWindPoint and LoadGame bodies written from the local listings; declarations added to the existing unit header. Stamped as a twin of matched 0x5dcb70 (skyrim_shared/tempeffects/ActiveEffectReferenceEffectController_5dc9d0): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xdd0d40 Ownerdd0d40::LoadGame
#include "Ownerdd0d40.h"

// guess: same compiled code as matched 0x5dcb70 apart from relocated fields; its role here is not established.
void Ownerdd0d40::LoadGame(BGSLoadFormBuffer* a_buf) { LoadRefHandle(a_buf, &target); }
