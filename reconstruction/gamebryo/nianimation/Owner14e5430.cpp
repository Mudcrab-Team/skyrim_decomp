// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0xf5de10 (gamebryo/nianimation/NiMultiTargetTransformController): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x14e5430 Owner14e5430::GetInterpolatorCount
#include "Owner14e5430.h"
#include <cstring>

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Owner14e5430::Owner14e5430()
{
}

std::uint16_t Owner14e5430::GetInterpolatorCount() const
{
    return m_count;
}
