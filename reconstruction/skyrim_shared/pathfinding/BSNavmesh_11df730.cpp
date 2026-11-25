// Source exposure: mixed
// Code origin: original reconstruction from the assigned local target; community declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// 0x11df730 BSNavmesh::GetEdgeVertices
#include "BSNavmesh_11df730.h"

// EdgeVertexIndices, GetEdgeVertices: GUESS(low); original body from the assigned local target.
EdgeVertexIndices BSNavmesh::GetEdgeVertices(std::uint16_t triangle, std::uint32_t edge) const
{
    EdgeVertexIndices result;
    result.first = triangles[triangle].vertices[edge];
    result.second = triangles[triangle].vertices[static_cast<std::uint32_t>(static_cast<int>(edge + 1) % 3)];
    return result;
}
