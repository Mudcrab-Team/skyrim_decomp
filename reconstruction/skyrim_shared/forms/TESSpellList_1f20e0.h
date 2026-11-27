// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: original declarations adapted from the labelled community layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESSpellList, SpellData, actorEffects, spells, levSpells, shouts, numSpells, numlevSpells, numShouts, SpellItem, TESLevSpell, TESShout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESSpellList::HasShout: SIBLING(fo4-private@1b765c70, author-permission)
// vtable: STANDIN OBSERVED
#pragma once
#include <cstdint>

class SpellItem;
class TESLevSpell;
class TESShout;

class TESSpellList
{
public:
    struct SpellData
    {
        SpellItem** spells;
        TESLevSpell** levSpells;
        TESShout** shouts;
        std::uint32_t numSpells;
        std::uint32_t numlevSpells;
        std::uint32_t numShouts;
    };

    bool HasShout(TESShout* value) const;

    void* vtable;
    SpellData* actorEffects;
};
