// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x1492b90 ObjectTypeInfo::GetVariableCount
#include "ObjectTypeInfo_1492b90.h"

// Sum variable counts across this type and its linked parent types while linked.
std::uint32_t ObjectTypeInfo::GetVariableCount() const
{
    std::uint32_t count = 0;
    for (const ObjectTypeInfo* cur = this; cur != nullptr; cur = cur->parent) {
        if ((cur->flags & 3u) != 3u) {
            break;
        }
        count += (cur->flags >> 8) & 0x3FFu;
    }
    return count;
}
