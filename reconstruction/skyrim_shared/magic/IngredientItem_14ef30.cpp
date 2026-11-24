// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14ef30 IngredientItem::LearnAllEffects
// Adapted bodies: none
#include "IngredientItem_14ef30.h"

void IngredientItem::LearnAllEffects()
{
    for (std::uint32_t index = 0; index < 4; ++index) {
        std::uint32_t flags = knownEffectFlags;
        flags |= 1u << index;
        knownEffectFlags = static_cast<std::uint16_t>(flags);
        AddChange(0x80000000u);
    }
}
