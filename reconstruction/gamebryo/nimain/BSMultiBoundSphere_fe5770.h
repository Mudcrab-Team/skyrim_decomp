// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, NiPlane, NiFrustumPlanes, BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z, BSMultiBoundSphere::WithinFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPlane::normal, NiPlane::constant, NiFrustumPlanes::planes, NiFrustumPlanes::activePlanes, BSMultiBoundSphere::unk00, BSMultiBoundSphere::center, BSMultiBoundSphere::radius: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiPlane
{
    NiPoint3 normal;
    float constant;
};
static_assert(sizeof(NiPlane) == 0x10, "NiPlane size");

struct NiFrustumPlanes
{
    NiPlane planes[6];
    std::uint32_t activePlanes;
};
static_assert(offsetof(NiFrustumPlanes, activePlanes) == 0x60, "activePlanes offset");

class BSMultiBoundSphere
{
public:
    bool WithinFrustum(const NiFrustumPlanes& a_planes) const;

    std::uint8_t unk00[0x18];
    NiPoint3 center;
    float radius;
};
static_assert(offsetof(BSMultiBoundSphere, center) == 0x18, "center offset");
static_assert(offsetof(BSMultiBoundSphere, radius) == 0x24, "radius offset");
static_assert(sizeof(BSMultiBoundSphere) == 0x28, "BSMultiBoundSphere size");
