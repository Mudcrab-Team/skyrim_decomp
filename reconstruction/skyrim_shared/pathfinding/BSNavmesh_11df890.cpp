// Code origin: adapted; GetTriangleVertices body from the sibling source cited below; declarations adapted from CommonLibSSE-NG.
// 0x11df890 BSNavmesh::GetTriangleVertices
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshVertex, BSNavmeshTriangle, NiPoint3, vertices, triangles, location, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetTriangleVertices: SYMBOLS(fnv-x360-pdb)
// VertexArray, TriangleArray: STANDIN GUESS(low); minimal array prefixes.
// unk00, unk08, unk18, unk20, unk30, unk38: GUESS(low); unaccessed storage.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/pathfinding/navmesh.cpp:603
// GetTriangleVertices body: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); adapted with typed x64 pointers.
#include "BSNavmesh_11df890.h"

void BSNavmesh::GetTriangleVertices(std::uint16_t triangleIndex, NiPoint3** first, NiPoint3** second, NiPoint3** third)
{
    const BSNavmeshTriangle* triangle = &triangles.data[triangleIndex];
    *first = &vertices.data[triangle->vertices[0]].location;
    *second = &vertices.data[triangle->vertices[1]].location;
    *third = &vertices.data[triangle->vertices[2]].location;
}
