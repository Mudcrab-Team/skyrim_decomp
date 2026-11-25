// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESFileContainer.cpp:218
// 0x1e2940 TESFileArray::WouldEqualMinusEnd
#include "TESFileArray_1e2940.h"

bool TESFileArray::WouldEqualMinusEnd(const TESFileArray& a_array) const
{
    std::uint32_t count = uiNumElements;
    bool result = count == a_array.uiNumElements - 1;
    for (std::uint32_t i = 0; result; ++i) {
        if (i >= count)
            break;
        result = pElements[i] == a_array.pElements[i];
    }
    return result;
}
