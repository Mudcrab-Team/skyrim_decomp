// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xeff550 BSFaceGenNiNode::sub_140C74090
#include "BSFaceGenNiNode_eff550.h"

// Recursively registers named scene-graph objects with the target facegen node.
void BSFaceGenNiNode::sub_140C74090(NiAVObject* a_object, NiNode* a_target)
{
    if (!a_object || !a_target)
    {
        return;
    }

    if (a_object->name)
    {
        a_target->RegisterNamedChild(&a_object->name, a_object);
    }

    NiNode* node = a_object->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            sub_140C74090(node->children[i], a_target);
        }
    }
}
