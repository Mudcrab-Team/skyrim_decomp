// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1cb640 Obj1cb640::FindValue
// Adapted bodies: none.
#include "Obj1cb640.h"

// Looks up the first non-zero value matching a_target->id14 in array4C0.
std::uint32_t Obj1cb640::FindValue(const Target1cb640* a_target) const
{
    const Array1cb640* arr = array4C0;
    std::uint32_t result = 0;
    for (std::uint32_t i = 0; result == 0 && i < arr->size; ++i) {
        if (arr->data[i].id == a_target->id14) {
            result = arr->data[i].value;
        }
    }
    return result;
}
