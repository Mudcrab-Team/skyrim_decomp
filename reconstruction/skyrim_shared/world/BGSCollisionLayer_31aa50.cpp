// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// Adapted bodies: none
// 0x31aa50 BGSCollisionLayer::GetCollidesWithMask
#include "BGSCollisionLayer_31aa50.h"

// At: GUESS(low)
template <class T>
static T& At(const void* a_base, std::uint32_t a_offset)
{
    return *reinterpret_cast<T*>(const_cast<char*>(static_cast<const char*>(a_base)) + a_offset);
}

// CollisionLayerEntry, index: GUESS(low)
struct CollisionLayerEntry
{
    char pad[0x30];
    std::int32_t index;
};

std::uint64_t BGSCollisionLayer::GetCollidesWithMask() const
{
    std::uint64_t mask = 0;
    const std::uint32_t count = At<std::uint32_t>(this, 0x58);
    if (count != 0) {
        CollisionLayerEntry** entry = At<CollisionLayerEntry**>(this, 0x48);
        std::uint64_t remaining = count;
        do {
            const std::int32_t index = (*entry)->index;
            ++entry;
            mask |= 1ll << index;
            --remaining;
        } while (remaining != 0);
    }
    return mask;
}
