// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimationGraphManager, ProcessEvent, BSAnimationGraphEvent, BSTEventSource, BSEventNotifyControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HandleEvent: GUESS(low)
// 0xbc15e0 BSAnimationGraphManager::ProcessEvent
#include "BSAnimationGraphManager_bc15e0.h"
BSEventNotifyControl BSAnimationGraphManager::ProcessEvent(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source) { HandleEvent(event, source); return BSEventNotifyControl::kContinue; }
