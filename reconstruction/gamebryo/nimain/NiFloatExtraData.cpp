// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none.
// 0xf10f90 NiFloatExtraData::IsEqual
#include "NiFloatExtraData.h"

// Body done: RVA 0xf10f90, 22 bytes, NiFloatExtraData::IsEqual. The null test comes first, so the
// other object's value is read only after it.
bool NiFloatExtraData::IsEqual(NiObject* a_object)
{
    if (a_object == nullptr) {
        return false;
    }
    auto* other = static_cast<NiFloatExtraData*>(a_object);
    return value == other->value;
}
