// Source exposure: mixed (pinned image and cited public names).
// Code origin: original implementation using the observed cleanup and partial layouts. Stamped as a twin of matched 0xf1e680 (gamebryo/nimain/NiBackToFrontAccumulator): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xfdff80 Ownerfdff80::IsEqual
#include "Ownerfdff80.h"

// guess: same compiled code as matched 0xf1e680 apart from relocated fields; its role here is not established.
bool Ownerfdff80::IsEqual(NiObject* other)
{
    return BaseEquals(other) != 0;
}
