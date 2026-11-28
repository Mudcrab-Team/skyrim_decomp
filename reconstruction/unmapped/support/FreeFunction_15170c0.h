// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Function15170c0, treated as adapted: shaped like BuildTransformMatrix in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap.cpp:291
// SPDX-License-Identifier: CC0-1.0
// Vec3_15170c0, Transform_15170c0, Matrix4_15170c0, g_origin_15170c0, Function15170c0, x, y, z, rot, translate, scale, m, out, transform: GUESS(low)
#pragma once

#include <cstddef>

struct Vec3_15170c0
{
    float x;  // 0x00
    float y;  // 0x04
    float z;  // 0x08
};

struct Transform_15170c0
{
    float rot[3][3];         // 0x00
    Vec3_15170c0 translate;  // 0x24
    float scale;             // 0x30
};
static_assert(offsetof(Transform_15170c0, translate) == 0x24, "translate offset");
static_assert(offsetof(Transform_15170c0, scale) == 0x30, "scale offset");

struct Matrix4_15170c0
{
    float m[4][4];  // 0x00
};

extern Vec3_15170c0 g_origin_15170c0;

void Function15170c0(Matrix4_15170c0* out, const Transform_15170c0* transform);
