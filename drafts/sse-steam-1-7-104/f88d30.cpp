// Near miss: 1.0 alignment distance | register-schedule
// Exposure detail: (community names; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf88d30 NiTextKeyExtraData::IsEqual

#include "include/f88d30/NiTextKeyExtraData_f88d30.h"
bool NiTextKeyExtraData::IsEqual(NiObject* other)
{
    if (!other || !NiObject::IsEqual(other))
        return false;
    const auto* data = static_cast<const NiTextKeyExtraData*>(other);
    if (keyCount != data->keyCount) {
        return false; }
    for (std::uint32_t i = 0; i < keyCount; ++i) {
        if (data->keys[i].time != keys[i].time ||
            keys[i].text != data->keys[i].text)
            return false;
    }
    return true;
}
