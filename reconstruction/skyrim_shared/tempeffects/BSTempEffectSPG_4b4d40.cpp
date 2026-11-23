// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4b4d40 BSTempEffectSPG::DetachGeometry
// Adapted bodies: none
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
#include "BSTempEffectSPG_4b4d40.h"

void BSTempEffectSPG::DetachGeometry()
{
    NiAVObject* geometry = spg3D;
    if (geometry) {
        NiNode* parent = geometry->parent;
        if (parent) {
            parent->DetachChild2(geometry);
        }
    }
}
