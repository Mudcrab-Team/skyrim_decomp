// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, vertices, triangles: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); each is the data pointer of the community BSTArray
// BSNavmesh::GetEdgeVertexPair, VertexPair, NavmeshVertex, first, second: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

// Minimal stand-in: one vertex of twelve bytes.
struct NavmeshVertex
{
    float x;
    float y;
    float z;
};

struct VertexPair
{
    NavmeshVertex* first;
    NavmeshVertex* second;
};

class BSNavmesh
{
public:
    VertexPair GetEdgeVertexPair(std::uint16_t a_triangle, std::int32_t a_corner);  // compared: 0x11df780

    std::uint8_t unk00[0x10];
    NavmeshVertex* vertices;
    std::uint8_t unk18[0x10];
    std::uint16_t* triangles;
};
