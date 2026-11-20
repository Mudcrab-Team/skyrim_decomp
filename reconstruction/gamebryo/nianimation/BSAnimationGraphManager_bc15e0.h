// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSAnimationGraphManager, ProcessEvent, BSAnimationGraphEvent, BSTEventSource, BSEventNotifyControl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HandleEvent: GUESS(low)
#pragma once
class BSAnimationGraphEvent; template<class T> class BSTEventSource;
enum class BSEventNotifyControl { kContinue = 0, kStop = 1 };
class BSAnimationGraphManager { public:
 BSEventNotifyControl ProcessEvent(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source);
 void HandleEvent(const BSAnimationGraphEvent* event, BSTEventSource<BSAnimationGraphEvent>* source);
};
