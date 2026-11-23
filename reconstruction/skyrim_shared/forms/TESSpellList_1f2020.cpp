// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1f2020 TESSpellList::ContainsSpell
// Adapted bodies: none
#include "TESSpellList_1f2020.h"

bool TESSpellList::ContainsSpell(const SpellItem* a_item) const
{
    bool found = false;
    if (actorEffects)
    {
        const std::uint32_t count = actorEffects->numSpells;
        for (std::uint32_t i = 0; i < count; ++i)
        {
            if (actorEffects->spells[i] == a_item)
            {
                found = true;
                i = count;
            }
        }
    }
    return found;
}
