// Source exposure: mixed (community declarations, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header declarations/BaseFormComponent.h for BaseFormComponent.
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESSpellList.cpp:339
// TESSpellList, TESSpellList::SpellData, actorEffects, levSpells, numlevSpells: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESSpellList::HasLeveledSpell: SIBLING(fo4-private@1b765c70, author-permission)
// TESLevSpell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// spells, shouts, numSpells, numShouts, pad24, ~TESSpellList, InitializeDataComponent, ClearDataComponent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include "declarations/BaseFormComponent.h"

class TESLevSpell;

class TESSpellList : public BaseFormComponent
{
public:
    struct SpellData
    {
        void** spells;  // 00
        TESLevSpell** levSpells;  // 08
        void** shouts;  // 10
        std::uint32_t numSpells;  // 18
        std::uint32_t numlevSpells;  // 1C
        std::uint32_t numShouts;  // 20
        std::uint32_t pad24;  // 24
    };
    static_assert(sizeof(SpellData) == 0x28, "SpellData size");

    ~TESSpellList() override;  // 00
    void InitializeDataComponent() override;  // 01
    void ClearDataComponent() override;  // 02

    bool HasLeveledSpell(TESLevSpell* a_spell) const;  // compared: 0x1f2080

    SpellData* actorEffects;  // 08
};
static_assert(sizeof(TESSpellList) == 0x10, "TESSpellList size");
