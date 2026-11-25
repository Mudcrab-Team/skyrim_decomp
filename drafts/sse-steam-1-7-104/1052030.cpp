// Near miss: 15.0 alignment distance | control-flow
// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1052030 NiAVObject::FindCollisionObjectRecursive

#include "include/1052030/NiAVObject_1052030.h"

NiCollisionObject* NiAVObject::FindCollisionObjectRecursive(NiAVObject* object)
{
    if (object) {
    if (auto* collision = object->collisionObject)
        return collision;
    NiCollisionObject* result = nullptr;
    if (object->AsNode()) {
        auto* node = static_cast<NiNode*>(object);
        for (std::uint32_t index = 0; index < node->size && !result; index = index + 1) {
            auto* child = node->data[index];
            if (child)
                result = FindCollisionObjectRecursive(child);
        }
    }
    return result;
} else {
        return nullptr; }
}
