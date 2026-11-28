// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x275fa0 Obj275fa0::Function275fa0
// Adapted bodies: none
#include "Obj275fa0.h"

// Recursively searches a scene node tree in reverse child order for a geometry matching a_name.
SceneObj275fa0* Obj275fa0::Function275fa0(SceneObj275fa0* a_object, const char* a_name)
{
    if (!a_object) {
        return nullptr;
    }
    SceneObj275fa0* node = a_object->AsNode();
    if (node) {
        for (std::uint32_t i = node->childCount; i > 0u; ) {
            SceneObj275fa0* child = node->children[--i].ptr;
            SceneObj275fa0* found = Function275fa0(child, a_name);
            if (found) {
                return found;
            }
        }
        return nullptr;
    }
    if (a_object->AsGeometry() && a_object->name10 && _stricmp(a_name, a_object->name10) == 0) {
        return a_object;
    }
    return nullptr;
}
