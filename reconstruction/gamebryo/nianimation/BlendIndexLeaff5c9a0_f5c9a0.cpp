// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf5c9a0 BlendIndexLeaff5c9a0::GetHighestWeightedIndex
#include "BlendIndexLeaff5c9a0_f5c9a0.h"

std::uint8_t BlendIndexLeaff5c9a0::GetHighestWeightedIndex() const
{
    if (count == 1) {
        return singleIndex;
    }
    std::uint8_t index = 0;
    float highest = 0.0f;
    std::uint8_t best = 0xff;
    for (; index < arraySize; ++index) {
        const auto& item = items[index];
        if (item.interpolator && item.weight > highest) {
            best = index;
            highest = item.weight;
        }
    }
    // NOTE: the original retains a separate no-result branch.
    if (best == 0xff) {
        return 0xff;
    }
    return best;
}
