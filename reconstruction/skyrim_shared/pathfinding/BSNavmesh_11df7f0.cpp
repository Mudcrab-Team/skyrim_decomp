// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiPoint3::operator= as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// SPDX-License-Identifier: CC0-1.0
// BSNavmesh: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSNavmesh::Function11df7f0: GUESS(low)
// 0x11df7f0 BSNavmesh::Function11df7f0
#include "BSNavmesh_11df7f0.h"

// Copy the two endpoint vertices for a triangle edge.
bool BSNavmesh::Function11df7f0(std::uint16_t a_triIndex, std::int32_t a_edgeIndex, NiPoint3& a_outV0, NiPoint3& a_outV1) const
{
    const std::uint32_t next = static_cast<std::uint32_t>((a_edgeIndex + 1) % 3);
    const std::uint16_t v1 = triangles[a_triIndex].vertices[next];
    const std::uint16_t v0 = triangles[a_triIndex].vertices[static_cast<std::uint32_t>(a_edgeIndex)];
    a_outV0 = vertices[v0];
    a_outV1 = vertices[v1];
    return true;
}
