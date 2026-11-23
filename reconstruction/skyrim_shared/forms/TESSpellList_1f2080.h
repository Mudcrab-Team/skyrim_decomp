// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESSpellList, TESSpellList::SpellData, SpellItem, TESLevSpell, TESShout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// TESSpellList::actorEffects, SpellData::spells, SpellData::levSpells, SpellData::shouts, SpellData::numSpells, SpellData::numlevSpells, SpellData::numShouts: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names only
// TESSpellList::unk00: GUESS(low); covers the vtable pointer
// TESSpellList::ContainsLevSpell: GUESS(low)
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
        std::uint32_t pad24;
    };

    bool ContainsLevSpell(const TESLevSpell* a_item) const;  // compared: 0x1f2080

    void* unk00;
    SpellData* actorEffects;
};
