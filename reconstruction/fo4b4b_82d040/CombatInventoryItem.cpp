// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// CombatInventoryItem::GetDescription: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:140
// TESForm, CombatInventoryItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/T/TESForm.h, include/RE/B/BaseFormComponent.h and include/RE/C/CombatInventoryItem.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x82d040 CombatInventoryItem::GetDescription
#include "CombatInventoryItem.h"
#include <cstring>
void CombatInventoryItem::GetDescription(char* buffer, unsigned length) const { strcpy_s(buffer, length, item->GetFormEditorID()); }
