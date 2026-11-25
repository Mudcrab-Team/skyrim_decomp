// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x151d10 (skyrim_shared/magic/MagicItem_151d10): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0x8087f0 Owner8087f0::Function8087f0
#include "Owner8087f0.h"

// guess: same compiled code as matched 0x151d10 apart from relocated fields; its role here is not established.
void Owner8087f0::Function8087f0(EffectVisitor* visitor)
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
