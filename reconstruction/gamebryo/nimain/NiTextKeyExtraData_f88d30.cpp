// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0xf88d30 NiTextKeyExtraData::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiTextKeyExtraData_f88d30.h"

// Equal when the key counts match and every key agrees in time and text.
bool NiTextKeyExtraData::IsEqual(NiObject* other)
{
    if (!other || !NiObject::IsEqual(other)) {
        return false;
    }
    const auto* data = static_cast<const NiTextKeyExtraData*>(other);
    if (keyCount != data->keyCount) {
        return false;
    }
    for (std::uint32_t i = 0; i < keyCount; ++i) {
        const auto& theirs = data->keys[i];
        const auto& mine = keys[i];
        if (mine.time != theirs.time || mine.text != theirs.text) {
            return false;
        }
    }
    return true;
}
