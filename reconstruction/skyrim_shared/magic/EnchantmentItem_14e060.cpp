// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// EnchantmentItem::SetDelivery: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:81
// SpellItem, MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/E/EnchantmentItem.h, include/RE/M/MagicItem.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h and include/RE/B/BGSKeywordForm.h, include/RE/B/BGSEquipType.h, include/RE/B/BGSMenuDisplayObject.h and include/RE/T/TESDescription.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14e060 EnchantmentItem::SetDelivery
#include "EnchantmentItem_14e060.h"
void EnchantmentItem::SetDelivery(MagicSystem::Delivery value) { if (IsValidDelivery(value)) { data.delivery = value; MagicItem::SetDelivery(value); } }
