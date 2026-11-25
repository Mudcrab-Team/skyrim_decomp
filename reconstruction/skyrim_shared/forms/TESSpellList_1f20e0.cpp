// Source exposure: mixed (community declarations; permitted sibling game code; pinned image observations).
// Code origin: adapted from the permitted anonymous game-code sibling
// SPDX-License-Identifier: LicenseRef-Author-Permission
// 0x1f20e0 TESSpellList::HasShout
// Adapted bodies: TESSpellList::HasShout, fo4-private@1b765c70, Shared/FormComponents/TESSpellList.cpp:359-376, author-permission
#include "TESSpellList_1f20e0.h"

bool TESSpellList::HasShout(TESShout* value) const
{
    bool found = false;
    SpellData* data = actorEffects;
    if (data) {
        for (std::uint32_t index = 0; index < data->numShouts; ++index) {
            if (value == data->shouts[index]) {
                found = true;
                index = data->numShouts;
            }
        }
    }
    return found;
}
