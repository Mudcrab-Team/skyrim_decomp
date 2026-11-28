// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function15170c0, treated as adapted: shaped like BuildTransformMatrix in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap.cpp:291
// SPDX-License-Identifier: CC0-1.0
// 0x15170c0 Function15170c0
#include "FreeFunction_15170c0.h"

// Builds a 4x4 matrix from a scaled transposed 3x3 rotation and origin-relative translation.
void Function15170c0(Matrix4_15170c0* out, const Transform_15170c0* transform)
{
    float scale = transform->scale;
    out->m[0][0] = scale * transform->rot[0][0];
    out->m[0][1] = scale * transform->rot[1][0];
    out->m[0][2] = scale * transform->rot[2][0];
    out->m[0][3] = 0.0f;

    out->m[1][0] = scale * transform->rot[0][1];
    out->m[1][1] = scale * transform->rot[1][1];
    out->m[1][2] = scale * transform->rot[2][1];
    out->m[1][3] = 0.0f;

    out->m[2][0] = scale * transform->rot[0][2];
    out->m[2][1] = scale * transform->rot[1][2];
    out->m[2][2] = scale * transform->rot[2][2];
    out->m[2][3] = 0.0f;

    out->m[3][0] = transform->translate.x - g_origin_15170c0.x;
    out->m[3][1] = transform->translate.y - g_origin_15170c0.y;
    out->m[3][2] = transform->translate.z - g_origin_15170c0.z;
    out->m[3][3] = 1.0f;
}
