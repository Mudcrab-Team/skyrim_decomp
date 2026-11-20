// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCasterLight, CheckStopCast, CombatController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CheckCondition: GUESS(low)
#pragma once
class CombatController { public: bool CheckCondition(); };
class CombatMagicCasterLight { public: bool CheckStopCast(CombatController* controller); };
