// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// SpellItem::IgnoreLOS, SpellItem::GetNoAbsorb, SpellItem::GetNoDualCastModifications: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:214
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:220
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:226
// SpellItem, MagicItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/S/SpellItem.h, include/RE/M/MagicItem.h, include/RE/T/TESBoundObject.h, include/RE/T/TESForm.h, include/RE/T/TESFullName.h and include/RE/B/BGSKeywordForm.h, include/RE/B/BGSEquipType.h, include/RE/B/BGSMenuDisplayObject.h and include/RE/T/TESDescription.h.
// names: GUESS(low); names and original signatures are tentative.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x155380 SpellItem::IgnoreLOS
// 0x1553a0 SpellItem::GetNoAbsorb
// 0x1553c0 SpellItem::GetNoDualCastModifications
#include "SpellItem_155380.h"
bool SpellItem::IgnoreLOS() const { return (GetData1()->flags >> 19) & 1; }
bool SpellItem::GetNoAbsorb() const { return (GetData1()->flags >> 21) & 1; }
bool SpellItem::GetNoDualCastModifications() const { return (GetData1()->flags >> 23) & 1; }
