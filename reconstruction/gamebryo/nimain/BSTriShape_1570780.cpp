// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1570780 BSTriShape::Function1570780
// Adapted bodies: none
#include "BSTriShape_1570780.h"

static bool IsExactType(SceneObject* a_object, const RttiInfo* a_rtti)
{
    return a_object && a_object->unk02() == a_rtti;
}

// Walks up the parent chain to the nearest object whose runtime type is the one stored in s_rtti.
SceneObject* BSTriShape::Function1570780(SceneObject* a_object)
{
    SceneObject* node = a_object;
    while (node && !IsExactType(node, &s_rtti)) {
        node = node->parent;
    }
    if (IsExactType(node, &s_rtti)) {
        return node;
    }
    return nullptr;
}
