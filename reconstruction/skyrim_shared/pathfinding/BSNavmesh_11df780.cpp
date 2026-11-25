// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x11df780 BSNavmesh::GetEdgeVertexPair
// Adapted bodies: none
#include "BSNavmesh_11df780.h"

VertexPair BSNavmesh::GetEdgeVertexPair(std::uint16_t a_triangle, std::int32_t a_corner)
{
    const std::size_t base = static_cast<std::size_t>(a_triangle) << 3;
    VertexPair result;
    result.first = &vertices[triangles[base + static_cast<std::uint32_t>(a_corner)]];
    const std::uint32_t next = static_cast<std::uint32_t>((a_corner + 1) % 3);
    result.second = &vertices[triangles[base + next]];
    return result;
}
