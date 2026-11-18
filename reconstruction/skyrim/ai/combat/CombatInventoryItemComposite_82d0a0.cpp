// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// CombatInventoryItemComposite::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:154
// CombatInventoryItem: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/C/CombatInventoryItem.h, include/RE/C/CombatObject.h and include/RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82d0a0 CombatInventoryItemComposite::SaveGame
#include "CombatInventoryItemComposite_82d0a0.h"
void CombatInventoryItemComposite::SaveGame(BGSSaveFormBuffer* buffer) const { CombatInventoryItem::SaveGame(buffer); buffer->SaveFormID(secondaryItem, 0); }
