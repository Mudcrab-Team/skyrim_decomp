// Code origin: GetManagerHandlesSaveLoad, GetWindPoint and LoadGame bodies written from the local listings; declarations added to the existing unit header.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x5dc9d0 ActiveEffectReferenceEffectController::GetManagerHandlesSaveLoad
// 0x5dcae0 ActiveEffectReferenceEffectController::GetWindPoint
// 0x5dcb70 ActiveEffectReferenceEffectController::LoadGame
#include "ActiveEffectReferenceEffectController.h"
bool ActiveEffectReferenceEffectController::GetManagerHandlesSaveLoad() const { return false; }
NiPoint3* ActiveEffectReferenceEffectController::GetWindPoint() { return &windPoint; }
void ActiveEffectReferenceEffectController::LoadGame(BGSLoadFormBuffer* a_buf) { LoadRefHandle(a_buf, &target); }
