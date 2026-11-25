// Source exposure: mixed
// Code origin: original reconstruction from the assigned local target; community declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshTriangle, vertices, triangles: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk08, unk10, unk18, unk20: GUESS(low); unaccessed prefix members.
// Partial BSNavmesh declaration: triangles represents only its array's data pointer.
// triangleFlags, traversalFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetEdgeVertexIndices: GUESS(low); inferred edge endpoint indices.
#pragma once
#include <cstddef>
#include <cstdint>

struct BSNavmeshTriangle
{
    std::uint16_t vertices[3];
    std::uint16_t triangles[3];
    std::uint16_t triangleFlags;
    std::uint16_t traversalFlags;
};
static_assert(sizeof(BSNavmeshTriangle) == 0x10, "triangle stride");
static_assert(offsetof(BSNavmeshTriangle, triangleFlags) == 0xC, "packed flags offset");

class BSNavmesh
{
public:
    bool GetEdgeVertexIndices(std::uint16_t triangle, std::uint32_t edge, std::uint16_t& first, std::uint16_t& second) const;

    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    BSNavmeshTriangle* triangles;
};
static_assert(offsetof(BSNavmesh, triangles) == 0x28, "triangle array data offset");
