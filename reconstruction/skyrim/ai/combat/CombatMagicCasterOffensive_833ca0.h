// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatMagicCasterOffensive::CheckStopCast, CombatMagicCasterOffensive::CheckStartCast: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:85
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatMagicCaster.cpp:158
// CombatMagicCasterOffensive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/C/CombatMagicCasterOffensive.h, include/RE/C/CombatMagicCaster.h, include/RE/C/CombatObject.h and include/RE/A/AITimer.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
struct AITimer { float start, duration; };
extern float aiTime;
class CombatController;
class CombatObject { public: virtual ~CombatObject(); unsigned refCount; };
class CombatMagicCaster : public CombatObject { public: void* inventoryItem; void* magicItem; bool CheckCost(CombatController*); };
class CombatMagicCasterOffensive : public CombatMagicCaster { public: AITimer castTimer, waitTimer; bool CheckStopCast(CombatController*); bool CheckStartCast(CombatController*); };
