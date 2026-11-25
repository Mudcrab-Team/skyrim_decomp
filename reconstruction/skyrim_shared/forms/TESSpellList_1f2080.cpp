// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: adapted from the cited sibling body; checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESSpellList.cpp:339
// 0x1f2080 TESSpellList::HasLeveledSpell
#include "TESSpellList_1f2080.h"

bool TESSpellList::HasLeveledSpell(TESLevSpell* a_spell) const
{
    SpellData* data = actorEffects;
    bool found = false;
    if (data) {
        std::uint32_t count = data->numlevSpells;
        for (std::uint32_t i = 0; i < count; ++i) {
            if (data->levSpells[i] == a_spell) {
                found = true;
                i = data->numlevSpells;
            }
        }
    }
    return found;
}
