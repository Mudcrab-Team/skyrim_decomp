// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// AddScaledPoints: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// Globals: GUESS(low); placeholder name
#pragma once

struct NiPoint3;
struct Vec3;

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3 CrossProduct(NiPoint3 const& other) const;
};


struct Vec3
{
    float x;
    float y;
    float z;
    Vec3 operator*(float scale) const
    {
        Vec3 r;
        r.x = x * scale;
        r.y = y * scale;
        r.z = z * scale;
        return r;
    }
    Vec3& operator+=(const Vec3& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
};

struct Globals
{
};
