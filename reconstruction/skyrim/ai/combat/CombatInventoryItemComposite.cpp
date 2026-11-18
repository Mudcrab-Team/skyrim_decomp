// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// names: GUESS(low); names and signatures are hypotheses.
// CombatInventoryItemComposite::IsValid: SIBLING(fo4-private@1b765c70, author-permission); adapted behavior.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:150
// CombatInventoryItem: COMMUNITY(Ryan-rsm-McKenzie/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations from include/RE/C/CombatInventoryItem.h, include/RE/C/CombatObject.h and include/RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82d080 CombatInventoryItemComposite::IsValid
#include "CombatInventoryItemComposite.h"
bool CombatInventoryItemComposite::IsValid() const { return item && secondaryItem; }
