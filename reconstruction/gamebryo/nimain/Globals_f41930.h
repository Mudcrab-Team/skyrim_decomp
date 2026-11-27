// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ComputeBarycentric: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct Vec3f;


struct Vec3f
{
    float x;
    float y;
    float z;
    Vec3f(const Vec3f& a, const Vec3f& b) : x(a.x - b.x), y(a.y - b.y), z(a.z - b.z)
    {}
    float Dot(const Vec3f& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};

struct Globals
{
};
