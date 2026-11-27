// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPoint3::operator= as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: CC0-1.0
// NiPoint3, BSNavmeshTriangle, BSNavmesh: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3::x, NiPoint3::y, NiPoint3::z, BSNavmeshTriangle::vertices, BSNavmeshTriangle::triangles, BSNavmeshTriangle::triangleFlags, BSNavmeshTriangle::traversalFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// BSNavmesh::Function11df7f0, BSNavmesh::unk00, BSNavmesh::vertices, BSNavmesh::unk18, BSNavmesh::triangles: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    NiPoint3(const NiPoint3& a_rhs) :
        x(a_rhs.x),
        y(a_rhs.y),
        z(a_rhs.z)
    {}

    NiPoint3& operator=(const NiPoint3& a_rhs)
    {
        x = a_rhs.x;
        y = a_rhs.y;
        z = a_rhs.z;
        return *this;
    }

    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0x0C, "NiPoint3 size");

struct BSNavmeshTriangle
{
    std::uint16_t vertices[3];
    std::uint16_t triangles[3];
    std::uint16_t triangleFlags;
    std::uint16_t traversalFlags;
};
static_assert(sizeof(BSNavmeshTriangle) == 0x10, "BSNavmeshTriangle size");

class BSNavmesh
{
public:
    bool Function11df7f0(std::uint16_t a_triIndex, std::int32_t a_edgeIndex, NiPoint3& a_outV0, NiPoint3& a_outV1) const;

    std::uint8_t unk00[0x10];
    NiPoint3* vertices;
    std::uint8_t unk18[0x10];
    BSNavmeshTriangle* triangles;
};
static_assert(offsetof(BSNavmesh, vertices) == 0x10, "vertices offset");
static_assert(offsetof(BSNavmesh, triangles) == 0x28, "triangles offset");
