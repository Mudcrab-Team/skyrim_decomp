// Actor: EXE_RTTI
// Origin: original reconstruction informed by CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// Actor: EXE_RTTI
// Actor::RefreshState, Actor::CheckA, Actor::CheckB, Actor::CheckC, Actor::CheckD: GUESS(low)
class Actor { public:
 void RefreshState();
 bool CheckA(); int CheckB(); bool CheckC(); int CheckD();
};
