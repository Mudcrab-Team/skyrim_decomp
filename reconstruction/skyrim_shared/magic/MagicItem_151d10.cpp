// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151d10 MagicItem::VisitEffects
// Adapted bodies: none
#include "MagicItem_151d10.h"

void MagicItem::VisitEffects(EffectVisitor* visitor)
{
    std::uint32_t count = effectCount;
    if (count == 0)
        return;
    Effect** end = effects + count;
    for (Effect** it = effects; it != end; ++it) {
        if (visitor->Visit(*it) != 1)
            break;
    }
}
