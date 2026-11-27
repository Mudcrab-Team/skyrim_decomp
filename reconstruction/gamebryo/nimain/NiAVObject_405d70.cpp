// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports IsKindOf, NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// 0x405d70 NiAVObject::GetCollisionObject
#include "NiAVObject_405d70.h"

namespace
{
    bool IsKindOf(const NiCollisionObject* object, const NiRTTI* target)
    {
        for (const NiRTTI* rtti = object->GetRTTI(); rtti != nullptr; rtti = rtti->baseRTTI) {
            if (rtti == target) {
                return true;
            }
        }
        return false;
    }

    bhkCollisionObject* CastToCollisionObject(NiCollisionObject* object)
    {
        if (!object) {
            return nullptr;
        }
        return IsKindOf(object, &NiRTTI_bhkCollisionObject)
            ? static_cast<bhkCollisionObject*>(object)
            : nullptr;
    }
}

// Traverse a scene graph subtree and return the first bhkCollisionObject found.
std::uint32_t NiAVObject::GetCollisionObject(NiAVObject* object, bhkCollisionObject** outCollision)
{
    std::uint32_t result = 0;
    if (object) {
        bhkCollisionObject* found = CastToCollisionObject(object->collisionObject);
        *outCollision = found;
        result = found != nullptr ? 1u : 0u;

        NiNode* node = object->AsNode();
        if (node) {
            const std::uint32_t count = node->childrenSize;
            for (std::uint32_t i = 0; i < count && result != 1; ++i) {
                NiAVObject* child = node->GetAt(i);
                result = GetCollisionObject(child, outCollision);
            }
        }
    }
    return result;
}
