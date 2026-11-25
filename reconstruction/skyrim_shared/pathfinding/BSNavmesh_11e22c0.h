// 0x11e22c0 BSNavmesh::GetGridBounds
// Code origin: adapted; NiPoint3 assignment follows the sibling body cited below; minimal stand-in declarations use labelled sources.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// NiPoint3::operator=: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); adapted component assignment.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh, BSNavmeshGrid, NiPoint3, meshGrid, gridSize, columnSectionLen, rowSectionLen, gridBoundsMin, gridBoundsMax, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetGridBounds: GUESS(low); copies bounds and reports initialized grid state.
// unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98: GUESS(low); unaccessed storage.
#pragma once
#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x, y, z;
    NiPoint3& operator=(const NiPoint3& other)
    {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
};
struct BSNavmeshGrid
{
    std::uint32_t gridSize;
    float columnSectionLen, rowSectionLen;
    NiPoint3 gridBoundsMin, gridBoundsMax;
};
class BSNavmesh
{
public:
    bool GetGridBounds(NiPoint3* minimum, NiPoint3* maximum) const;
    std::uint64_t unk00, unk08, unk10, unk18, unk20, unk28, unk30, unk38;
    std::uint64_t unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78;
    std::uint64_t unk80, unk88, unk90, unk98;
    BSNavmeshGrid meshGrid;
};
static_assert(offsetof(BSNavmesh, meshGrid) == 0xA0, "grid offset");
static_assert(offsetof(BSNavmeshGrid, gridBoundsMin) == 0xC, "minimum offset");
static_assert(offsetof(BSNavmeshGrid, gridBoundsMax) == 0x18, "maximum offset");
