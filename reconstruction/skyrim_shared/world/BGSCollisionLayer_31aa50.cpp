// Source exposure: mixed (community declarations; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original typed reconstruction; declarations retained from the existing local class header.
// Adapted bodies: none
// 0x31aa50 BGSCollisionLayer::GetCollidesWithMask
#include "BGSCollisionLayer_31aa50.h"

// Accumulate one collision bit for each linked layer.
std::uint64_t BGSCollisionLayer::GetCollidesWithMask() const
{
    std::uint64_t mask = 0;
    if (collidesWith.size != 0) {
        BGSCollisionLayer* const* current = collidesWith.data;
        std::size_t remaining = collidesWith.size;
        do {
            mask |= std::int64_t{1} << (*current++)->collisionIdx;
        } while (--remaining != 0);
    }
    return mask;
}
