// Origin: original reconstruction; declarations informed by CommonLibSSE-NG headers.
// Source exposure: mixed (binary-analysis and community headers).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCasterLight, CheckStopCast, CombatController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CheckCondition: GUESS(low)
// 0x8368f0 CombatMagicCasterLight::CheckStopCast
#include "CombatMagicCasterLight_8368f0.h"
bool CombatMagicCasterLight::CheckStopCast(CombatController* controller) { return !controller->CheckCondition(); }
