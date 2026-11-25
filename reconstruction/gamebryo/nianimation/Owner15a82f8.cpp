// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// Code origin: Stamped as a twin of matched 0xbc15e0 (gamebryo/nianimation/BSAnimationGraphManager_bc15e0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimationGraphEvent, BSTEventSource, BSEventNotifyControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x15a82f8 Owner15a82f8::Function15a82f8
// HandleEvent: GUESS(low) STANDIN
#include "Owner15a82f8.h"

// guess: same compiled code as matched 0xbc15e0 apart from relocated fields; its role here is not established.
BSEventNotifyControl Owner15a82f8::Function15a82f8(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source) { HandleEvent(event, source); return BSEventNotifyControl::kContinue; }
