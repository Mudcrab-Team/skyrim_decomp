// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatInventoryItemRanged::GetOptimalRange, CombatInventoryItemRanged::CalculateScore: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:246
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:415
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/C/CombatInventoryItem.h and include/RE/C/CombatObject.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82d710 CombatInventoryItemRanged::GetOptimalRange
// 0x82d790 CombatInventoryItemRanged::CalculateScore
#include "CombatInventoryItemRanged.h"
float CombatInventoryItemRanged::GetOptimalRange() const { return (maxRange - minRange) * optimalRangePercent + minRange; }
float CombatInventoryItemRanged::CalculateScore(CombatController* c) const { return CalculateScore(c, item, secondary, maxRange); }
