// Source exposure: mixed (pinned image and public declarations).
// Code origin: original reconstruction from the pinned image with community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfcea20 BSMultiBoundAABB::Ctor
// 0xfceba0 BSMultiBoundAABB::Unk_28
#include "BSMultiBoundAABB_fcea20.h"

#include <cmath>

// g_initialBoundPoint: GUESS(low)
extern NiPoint3 g_initialBoundPoint;

BSMultiBoundAABB::BSMultiBoundAABB()
{
    unk1C.x = g_initialBoundPoint.x;
    unk1C.y = g_initialBoundPoint.y;
    unk1C.z = g_initialBoundPoint.z;
    unk2C.x = g_initialBoundPoint.x;
    unk2C.y = g_initialBoundPoint.y;
    unk2C.z = g_initialBoundPoint.z;
}

std::uint32_t BSMultiBoundAABB::Unk_28(const float* sphere)
{
    const NiPoint3 center{sphere[0], sphere[1], sphere[2]};
    const float radius = sphere[3];
    const float x = std::fabs(center.x - unk1C.x);
    const float halfX = unk2C.x;
    const float xInnerDistance = x - (halfX - radius);
    const float xOuterDistance = x - (halfX + radius);
    bool inside = !(xInnerDistance > 0.0f);
    bool overlaps = !(xOuterDistance > 0.0f);

    if (inside || overlaps) {
        const float halfY = unk2C.y;
        const float y = std::fabs(center.y - unk1C.y);
        if (inside) {
            inside &= !(y - (halfY - radius) > 0.0f);
        }
        overlaps &= !(y - (halfY + radius) > 0.0f);
        if (inside || overlaps) {
            const float dz = center.z - unk1C.z;
            const float halfZ = unk2C.z;
            const float z = std::fabs(dz);
            if (inside) {
                inside &= !(z - (halfZ - radius) > 0.0f);
            }
            overlaps &= !(z - (halfZ + radius) > 0.0f);
        }
    }
    return inside ? 2 : overlaps;
}
