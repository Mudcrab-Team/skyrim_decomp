// Source exposure: mixed (pinned image and cited public names).
// Code origin: original implementation using the observed cleanup and partial layouts.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf1e680 NiBackToFrontAccumulator::IsEqual
// Adapted bodies: none
#include "NiBackToFrontAccumulator.h"

bool NiBackToFrontAccumulator::IsEqual(NiObject* other)
{
    return BaseEquals(other) != 0;
}
