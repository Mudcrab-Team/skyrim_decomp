// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// 0xf8fdc0 NiBoolKey::Equal
#include "NiBoolKey_f8fdc0.h"

bool NiBoolKey::Equal(const NiAnimationKey& first, const NiAnimationKey& second)
{
    if (!NiAnimationKey::Equal(first, second)) {
        return false;
    }
    return static_cast<const NiBoolKey&>(first).value == static_cast<const NiBoolKey&>(second).value;
}
