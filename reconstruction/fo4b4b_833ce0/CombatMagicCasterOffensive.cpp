// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatMagicCasterOffensive::CheckStopCast, CombatMagicCasterOffensive::CheckStartCast: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:85
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:158
// CombatMagicCasterOffensive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/C/CombatMagicCasterOffensive.h, include/RE/C/CombatMagicCaster.h, include/RE/C/CombatObject.h and include/RE/A/AITimer.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x833ce0 CombatMagicCasterOffensive::CheckStopCast
// 0x833ca0 CombatMagicCasterOffensive::CheckStartCast
#include "CombatMagicCasterOffensive.h"
bool CombatMagicCasterOffensive::CheckStopCast(CombatController*) { return aiTime - castTimer.start > castTimer.duration; }
bool CombatMagicCasterOffensive::CheckStartCast(CombatController* controller) { return aiTime - waitTimer.start > waitTimer.duration && CheckCost(controller); }
