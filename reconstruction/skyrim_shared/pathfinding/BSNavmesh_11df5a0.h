// Source exposure: mixed
// Code origin: original reconstruction from the assigned local target; community declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshTriangle, vertices, triangles: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk08, unk10, unk18, unk20: GUESS(low); unaccessed prefix members.
// Partial BSNavmesh declaration: triangles represents only its array's data pointer.
// triangleFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; one packed word spans NG's two flag halves.
// ReadEdgeCover: GUESS(low); inferred cover value and side indicators.
#pragma once
#include <cstddef>
#include <cstdint>

struct BSNavmeshTriangle
{
    std::uint16_t vertices[3];
    std::uint16_t triangles[3];
    std::uint32_t triangleFlags;
};
static_assert(sizeof(BSNavmeshTriangle) == 0x10, "triangle stride");
static_assert(offsetof(BSNavmeshTriangle, triangleFlags) == 0xC, "packed flags offset");

class BSNavmesh
{
public:
    std::uint16_t ReadEdgeCover(std::uint16_t triangle, std::uint16_t edge, bool& left, bool& right) const;

    std::uint64_t unk00;
    std::uint64_t unk08;
    std::uint64_t unk10;
    std::uint64_t unk18;
    std::uint64_t unk20;
    BSNavmeshTriangle* triangles;
};
static_assert(offsetof(BSNavmesh, triangles) == 0x28, "triangle array data offset");
