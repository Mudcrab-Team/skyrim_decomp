// Source exposure: mixed
// Code origin: original reconstruction from the assigned local target; community declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x11df6e0 BSNavmesh::GetEdgeVertexIndices
#include "BSNavmesh_11df6e0.h"

// GetEdgeVertexIndices: GUESS(low); original body from the assigned local target.
bool BSNavmesh::GetEdgeVertexIndices(std::uint16_t triangle, std::uint32_t edge, std::uint16_t& first, std::uint16_t& second) const
{
    const BSNavmeshTriangle* face = &triangles[triangle];
    if (face) {
        first = face->vertices[edge];
        second = face->vertices[static_cast<std::uint32_t>(static_cast<int>(edge + 1) % 3)];
    }
    return face != nullptr;
}
