// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x405cc0 NiAVObject::CountRigidBodyMotionTypes
// Adapted bodies: none
#include "NiAVObject_405cc0.h"

// Recursively count rigid-body motion types across a scene graph subtree.
void NiAVObject::CountRigidBodyMotionTypes(NiAVObject* object, MotionTypeCounts* counts)
{
    if (!object) {
        return;
    }

    bhkCollisionObject* collision = object->GetCollisionObjectRef();
    if (collision) {
        bhkRigidBody* rigidBody = collision->GetRigidBody();
        if (rigidBody) {
            std::int32_t motionType;
            if (rigidBody->referencedObject) {
                motionType = rigidBody->referencedObject->motionType;
            } else {
                motionType = 5;
            }
            switch (motionType) {
            case 4:
                ++counts->fixedCount;
                break;
            case 5:
                ++counts->keyframedCount;
                break;
            default:
                ++counts->dynamicCount;
                break;
            }
        }
    }

    NiNode* node = object->AsNode();
    if (node) {
        for (std::uint32_t i = 0; i < node->childrenSize; ++i) {
            CountRigidBodyMotionTypes(node->children[i], counts);
        }
    }
}
