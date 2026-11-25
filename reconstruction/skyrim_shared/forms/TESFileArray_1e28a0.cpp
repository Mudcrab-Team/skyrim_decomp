// Source exposure: mixed (the pinned image listing; sibling shape).
// Code origin: adapted from the cited sibling body
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESFileContainer.cpp:202
// 0x1e28a0 TESFileArray::WouldEqual
#include "TESFileArray_1e28a0.h"

bool TESFileArray::WouldEqual(const TESFileArray& a_array, TESFile* a_last) const
{
    std::uint32_t size = a_array.uiNumElements;
    bool result = uiNumElements - 1 == size;
    std::uint32_t i = 0;
    while (result && i < size) {
        result = pElements[i] == a_array.pElements[i];
        ++i;
    }
    if (result)
        result = pElements[i] == a_last;
    return result;
}
