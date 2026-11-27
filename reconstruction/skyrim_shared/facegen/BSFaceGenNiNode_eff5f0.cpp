// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xeff5f0 BSFaceGenNiNode::sub_140C74130
#include "BSFaceGenNiNode_eff5f0.h"

// Recursively clears named scene-graph registrations from the target facegen node.
void BSFaceGenNiNode::sub_140C74130(NiAVObject* a_object, NiNode* a_target)
{
    if (!a_object || !a_target)
    {
        return;
    }

    if (a_object->name)
    {
        a_target->RegisterNamedChild(&a_object->name, nullptr);
    }

    NiNode* node = a_object->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            sub_140C74130(node->children[i], a_target);
        }
    }
}
