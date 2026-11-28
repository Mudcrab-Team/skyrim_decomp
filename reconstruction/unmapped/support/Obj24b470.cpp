// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x24b470 Obj24b470::IsDifferent
// Adapted bodies: none
#include "Obj24b470.h"

#include <cstring>

// Compare count, position, and item array bytes against another object.
bool Obj24b470::IsDifferent(const Obj24b470* other) const
{
    if (!other || count != other->count)
    {
        return true;
    }
    if (position.x != other->position.x || position.y != other->position.y || position.z != other->position.z)
    {
        return true;
    }
    if (count != 0 && std::memcmp(items, other->items, static_cast<std::size_t>(count) * sizeof(Item24b470)) != 0)
    {
        return true;
    }
    return false;
}
