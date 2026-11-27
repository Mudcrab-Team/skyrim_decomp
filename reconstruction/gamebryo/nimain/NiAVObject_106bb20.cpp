// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x106bb20 NiAVObject::UpdateActiveCollisionTransformRecursive
// Adapted bodies: none
#include "NiAVObject_106bb20.h"

// Recursively update world transforms and bounds for active collision subtrees.
void NiAVObject::UpdateActiveCollisionTransformRecursive(NiAVObject* object, bool forceUpdate)
{
    if (!object) {
        return;
    }

    NiCollisionObject* collision = object->collisionObject;
    if ((collision && collision->GetWorldObject() != nullptr) || forceUpdate) {
        object->RecalculateWorldTransform();
        NiUpdateData updateData;
        updateData.time = 0.0f;
        updateData.flags = 0;
        object->UpdateWorldData(&updateData);
        forceUpdate = true;
    }

    NiNode* node = object->AsNode();
    if (node) {
        for (std::uint32_t i = 0; i < node->childrenSize; ++i) {
            UpdateActiveCollisionTransformRecursive(node->children[i], forceUpdate);
        }
    }

    object->UpdateWorldBound();
}
