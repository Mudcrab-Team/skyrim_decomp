// Actor: EXE_RTTI
// Origin: original reconstruction; declarations informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6a69c0 Actor::CheckA
// 0x6a70a0 Actor::CheckB
// 0x6a70c0 Actor::CheckC
// 0x6a70e0 Actor::CheckD

#include "Actor.h"

bool Actor::CheckA() { RefreshState(); return false; }
int Actor::CheckB() { RefreshState(); return 0; }
bool Actor::CheckC() { RefreshState(); return false; }
int Actor::CheckD() { RefreshState(); return 0; }
