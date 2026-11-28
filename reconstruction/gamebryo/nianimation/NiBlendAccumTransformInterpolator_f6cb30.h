// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiBlendAccumTransformInterpolator, NiBlendAccumTransformInterpolator::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBlendInterpolator, NiPoint3, NiQuaternion, NiQuatTransform, gInvalidPoint3, gInvalidQuat, gInvalidScale, accumValue, unk68, unk70: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;  // 00
    float y;  // 04
    float z;  // 08
};
static_assert(sizeof(NiPoint3) == 0x0C, "NiPoint3 size");

struct NiQuaternion
{
    float w;  // 00
    float x;  // 04
    float y;  // 08
    float z;  // 0C
};
static_assert(sizeof(NiQuaternion) == 0x10, "NiQuaternion size");

extern NiPoint3 gInvalidPoint3;
extern NiQuaternion gInvalidQuat;
extern float gInvalidScale;

struct NiQuatTransform
{
    NiQuatTransform()
    {
        translate.x = gInvalidPoint3.x;
        translate.y = gInvalidPoint3.y;
        translate.z = gInvalidPoint3.z;
        rotate = gInvalidQuat;
        scale = gInvalidScale;
    }

    NiPoint3 translate;  // 00
    NiQuaternion rotate;  // 0C
    float scale;  // 1C
};
static_assert(sizeof(NiQuatTransform) == 0x20, "NiQuatTransform size");

class NiBlendInterpolator
{
public:
    NiBlendInterpolator();
    virtual ~NiBlendInterpolator();

    std::uint8_t unk08[0x40];  // 08
};
static_assert(sizeof(NiBlendInterpolator) == 0x48, "NiBlendInterpolator size");

class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
{
public:
    NiBlendAccumTransformInterpolator();  // compared: 0xf6cb30

    NiQuatTransform accumValue;  // 48
    std::uint64_t unk68;  // 68
    bool unk70;  // 70
};
static_assert(offsetof(NiBlendAccumTransformInterpolator, accumValue) == 0x48, "accumValue offset");
static_assert(offsetof(NiBlendAccumTransformInterpolator, unk68) == 0x68, "unk68 offset");
static_assert(offsetof(NiBlendAccumTransformInterpolator, unk70) == 0x70, "unk70 offset");
