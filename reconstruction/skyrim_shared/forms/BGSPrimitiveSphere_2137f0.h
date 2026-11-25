// Source exposure: mixed (CrashLogger size, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSPrimitive.cpp:250
// BGSPrimitiveSphere, BGSPrimitiveSphere::IsInside, NiPoint3: SIBLING(fo4-private@1b765c70, author-permission)
// BGSPrimitive: CRASHLOGGER_PDB(59818@2026.10.24); size 0x18
// bounds, unknown14: GUESS(low); the sibling names the vector Radii
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};

class BGSPrimitive
{
public:
    NiPoint3 bounds;  // 08
    std::uint32_t unknown14;  // 14
};

class BGSPrimitiveSphere : public BGSPrimitive
{
public:
    virtual bool IsInside(const NiPoint3& a_point) const;  // compared: 0x2137f0, slot not claimed
};
