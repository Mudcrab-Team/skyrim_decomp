// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// Adapted bodies: none known. The origin check reports IsKindOf, NiNode::GetAt as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:4166
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// 0xfdf410 NiAVObject::ContainsParticleSystemRecursive
#include "NiAVObject_fdf410.h"

namespace
{
    bool IsKindOf(const NiAVObject* object, const NiRTTI* target)
    {
        for (const NiRTTI* rtti = object->GetRTTI(); rtti != nullptr; rtti = rtti->baseRTTI) {
            if (rtti == target) {
                return true;
            }
        }
        return false;
    }
}

// Traverse a scene graph subtree and record whether any object is a particle system.
std::uint32_t NiAVObject::ContainsParticleSystemRecursive(NiAVObject* object, bool* outFound)
{
    std::uint32_t result = 0;
    if (object) {
        const bool isParticle = IsKindOf(object, &NiRTTI_NiParticleSystem);
        *outFound = isParticle;
        result = isParticle ? 1u : 0u;

        NiNode* node = object->AsNode();
        if (node) {
            const std::uint32_t count = node->childrenSize;
            for (std::uint32_t i = 0; i < count && result != 1; ++i) {
                NiAVObject* child = node->GetAt(i);
                result = ContainsParticleSystemRecursive(child, outFound);
            }
        }
    }
    return result;
}
