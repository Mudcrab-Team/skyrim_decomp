// Actor: STANDIN GUESS(low); partial target-bound receiver/callee view; no full layout or ownership claim.
// Origin: original reconstruction with cited adapted declarations and complete notices.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Source exposure: mixed; Drafted by gpt-6.1-terra.
// Origin: original implementation informed by pinned community declarations.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// Actor, MagicItem, GetSpellType, selectedSpells: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// HasSelectedSpell, unknownPrefix, UnknownSlot: STANDIN GUESS(medium); meaning of type 6 and wrapper name remain unknown.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6d6d00 HasSelectedSpell
#include "Actor.h"
namespace P2073 {
bool Actor::HasSelectedSpell(std::int32_t slot) {
    auto* item = selectedSpells[slot];
    return item && item->GetSpellType() != 6;
}
}
