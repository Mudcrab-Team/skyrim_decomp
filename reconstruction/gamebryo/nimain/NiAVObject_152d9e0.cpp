// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// 0x152d9e0 NiAVObject::SetBloodSplatterAlphaSourceRecursive
// Adapted bodies: none
#include "NiAVObject_152d9e0.h"

// Recursively assign the blood splatter shader alpha source across matching geometry in a subtree.
void NiAVObject::SetBloodSplatterAlphaSourceRecursive(NiAVObject* object, void* alphaSource)
{
    if (!object) {
        return;
    }

    if (object->AsGeometry()) {
        BSShaderProperty* shader = static_cast<BSGeometry*>(object)->shaderProperty;
        if (shader && shader->GetRTTI() == &NiRTTI_BSBloodSplatterShaderProperty) {
            shader->alphaSource = alphaSource;
        }
        return;
    }

    NiNode* node = object->AsNode();
    if (node) {
        const std::uint16_t count = node->childrenSize;
        for (std::uint16_t i = 0; i < count; ++i) {
            NiAVObject* child = node->children[i];
            if (child) {
                SetBloodSplatterAlphaSourceRecursive(child, alphaSource);
            }
        }
    }
}
