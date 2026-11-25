// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x21cd70 NiAVObject::HasSkinInstanceRecursive
// Adapted bodies: NiAVObject::HasSkinInstanceRecursive, from the Fallout 3 decompilation (CC0-1.0), statement order only; no names taken
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00440000_o2.cpp:15065
#include "NiAVObject_21cd70.h"

// True when the object or any descendant carries a skin instance.
bool NiAVObject::HasSkinInstanceRecursive(NiAVObject* a_object)
{
    bool result = false;
    if (!a_object) {
        return false;
    }
    BSGeometry* geometry = a_object->AsGeometry();
    if (geometry && geometry->skinInstance) {
        return true;
    }
    NiNode* node = a_object->AsNode();
    if (node) {
        for (std::uint32_t i = 0; i < node->childEnd; i++) {
            NiAVObject* child = node->children[i];
            if (child) {
                result = HasSkinInstanceRecursive(child);
                if (result) {
                    break;
                }
            }
        }
    }
    return result;
}
