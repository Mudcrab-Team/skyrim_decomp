// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x6d6820 PlayerCharacter::Function6d6820
// Adapted bodies: none
#include "PlayerCharacter_6d6820.h"

std::uint8_t PlayerCharacter::Function6d6820()
{
    std::uint8_t mask = 0;
    CasterSlot slot;
    for (slot.index = 0; slot.index < sizeof(magicCasters) / sizeof(magicCasters[0]); ++slot.index) {
        CasterRef ref;
        ref.caster = magicCasters[slot.index];
        if (ref.caster) {
            const std::int32_t source = ref.caster->GetCastingSource();
            if (ref.caster->currentSpell) {
                mask |= 1 << source;
            }
        }
    }
    return mask;
}
