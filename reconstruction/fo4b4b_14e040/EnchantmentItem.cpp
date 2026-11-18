// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// EnchantmentItem::SetCastingType, EnchantmentItem::InitFromChunk: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:74
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/EnchantmentItem.cpp:99
// EnchantmentItem, MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/E/EnchantmentItem.h, include/RE/M/MagicItem.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h and include/RE/B/BGSKeywordForm.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x14e040 EnchantmentItem::SetCastingType
// 0x14e260 EnchantmentItem::InitFromChunk
#include "EnchantmentItem.h"
void EnchantmentItem::SetCastingType(int type) { data.castingType = type; MagicItem::SetCastingType(type); }
void EnchantmentItem::InitFromChunk(TESFile* file) { data.InitFromChunk(file); }
