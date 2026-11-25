// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: adapted from the permitted anonymous game-code sibling
// SPDX-License-Identifier: LicenseRef-Author-Permission
// 0x1f2020 TESSpellList::HasSpell
// Adapted bodies: TESSpellList::HasSpell, fo4-private@1b765c70, Shared/FormComponents/TESSpellList.cpp:319-336, author-permission
#include "TESSpellList_1f2020.h"

bool TESSpellList::HasSpell(SpellItem* value) const
{
    bool found = false;
    SpellData* data = actorEffects;
    if (data) {
        for (std::uint32_t index = 0; index < data->numSpells; ++index) {
            if (data->spells[index] == value) {
                found = true;
                index = data->numSpells;
            }
        }
    }
    return found;
}
