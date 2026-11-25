// 0x11df890 BSNavmesh::GetTriangleVertices
// Code origin: original; minimal stand-in declarations informed by the labelled name and layout sources.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshVertex, BSNavmeshTriangle, NiPoint3, vertices, triangles, location, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetTriangleVertices: SYMBOLS(fnv-x360-pdb)
// VertexArray, TriangleArray: STANDIN GUESS(low); minimal array prefixes.
// unk00, unk08, unk18, unk20, unk30, unk38: GUESS(low); unaccessed storage.
#pragma once
#include <cstddef>
#include <cstdint>

struct NiPoint3 { float x, y, z; };
struct BSNavmeshVertex { NiPoint3 location; };
struct BSNavmeshTriangle
{
    std::uint16_t vertices[3];
    std::uint16_t triangles[3];
    std::uint16_t triangleFlags;
    std::uint16_t traversalFlags;
};
struct VertexArray { BSNavmeshVertex* data; std::uint64_t unk08, unk10; };
struct TriangleArray { BSNavmeshTriangle* data; std::uint64_t unk08, unk10; };
class BSNavmesh
{
public:
    void GetTriangleVertices(std::uint16_t triangleIndex, NiPoint3** first, NiPoint3** second, NiPoint3** third);
    std::uint64_t unk00, unk08;
    VertexArray vertices;
    TriangleArray triangles;
};
static_assert(offsetof(BSNavmesh, vertices) == 0x10, "vertex array offset");
static_assert(offsetof(BSNavmesh, triangles) == 0x28, "triangle array offset");
static_assert(sizeof(BSNavmeshTriangle) == 0x10, "triangle stride");
