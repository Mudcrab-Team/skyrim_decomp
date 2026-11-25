// Near miss: 33.57% | inline-set
// Exposure detail: (community layouts and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x151a00 MagicItem::GetCostliestEffectItem

#include "include/151a00/MagicItem_151a00.h"

Effect* MagicItem::GetCostliestEffectItem(std::uint32_t delivery, bool includeInactive)
{
    CostliestEffectVisitor visitor(delivery, includeInactive);
    CostliestEffectVisitor* traversal = &visitor;
    std::uint32_t count = effectCount;
    if (count) {
        Effect** end = effects + count;
        for (Effect** it = effects; it != end; ++it) {
            if (traversal->Visit(*it) != 1)
                break;
        }
    }
    return visitor.result;
}
