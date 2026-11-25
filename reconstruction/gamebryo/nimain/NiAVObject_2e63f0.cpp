// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x2e63f0 NiAVObject::SetControllerFieldRecursive
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
#include "NiAVObject_2e63f0.h"

void NiAVObject::SetControllerFieldRecursive(NiAVObject* object, float value)
{
    if (!object)
        return;
    for (auto* controller = object->controllers; controller; controller = controller->next)
        controller->phase = value;
    auto* node = object->AsNode();
    if (node) {
        for (std::uint32_t index = 0; index < node->size; ++index)
            SetControllerFieldRecursive(node->data[index], value);
    }
}
