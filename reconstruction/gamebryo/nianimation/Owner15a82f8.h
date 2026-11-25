// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// Code origin: Stamped as a twin of matched 0xbc15e0 (gamebryo/nianimation/BSAnimationGraphManager_bc15e0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimationGraphEvent, BSTEventSource, BSEventNotifyControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function15a82f8, Owner15a82f8: GUESS(low) STANDIN
// HandleEvent: GUESS(low) STANDIN
#pragma once
#include "BSAnimationGraphManager_bc15e0.h"

class Owner15a82f8 { public:
 BSEventNotifyControl Function15a82f8(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source);
 void HandleEvent(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source);
};

