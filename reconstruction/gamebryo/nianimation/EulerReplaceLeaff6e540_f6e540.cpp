// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf6e540 EulerReplaceLeaff6e540::ReplaceKeys
#include "EulerReplaceLeaff6e540_f6e540.h"

void EulerReplaceLeaff6e540::ReplaceKeys(std::uint8_t axis, std::uint32_t count, void* replacement)
{
    if (keys[axis]) {
        gEulerDestroyersf6e540[types[axis]](keys[axis]);
    }
    keys[axis] = replacement;
    counts[axis] = count;
    cursors[axis] = 0;
}
