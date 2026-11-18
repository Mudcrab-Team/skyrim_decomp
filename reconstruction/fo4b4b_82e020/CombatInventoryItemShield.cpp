// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatInventoryItemShield::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:342
// CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/C/CombatInventoryItem.h and include/RE/C/CombatObject.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82e020 CombatInventoryItemShield::SaveGame
#include "CombatInventoryItemShield.h"
void CombatInventoryItemShield::SaveGame(SaveBuffer* buffer) { CombatInventoryItem::SaveGame(buffer); buffer->SaveDataEndian(&maxRange, 4, 4, 0); }
