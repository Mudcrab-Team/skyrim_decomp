// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x104d720 NiAVObject::VisitCollisionObjectTree
// Adapted bodies: none
#include "NiAVObject_104d720.h"

// Visit collision world objects in a scene graph subtree and invoke a callback on each.
void NiAVObject::VisitCollisionObjectTree(
    NiAVObject* object,
    CollisionVisitorData* data,
    VisitCallback callback)
{
    if (!object) {
        return;
    }

    NiCollisionObject* collision = object->collisionObject;
    bhkWorldObject* worldObject = collision ? collision->GetWorldObject() : nullptr;

    if (data->skipFlagUpdate == 0) {
        object->flags.selectiveUpdate = 1;
        object->flags.selectiveUpdateTransforms = 1;
        object->flags.selectiveUpdateRigid = 0;
    }

    if (worldObject) {
        callback(worldObject, data);
    }

    if (data->recurse) {
        NiNode* node = object->AsNode();
        if (node) {
            for (std::uint32_t i = 0; i < node->childrenSize; ++i) {
                VisitCollisionObjectTree(node->children[i], data, callback);
            }
        }
    }
}
