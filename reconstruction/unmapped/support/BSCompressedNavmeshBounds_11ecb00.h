// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSCompressedNavmeshBounds: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, gZeroPoint3, minBound, maxBound, unk18, unk20, unk28: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    NiPoint3() {}
    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}

    float x;
    float y;
    float z;
};

extern NiPoint3 gZeroPoint3;

class BSCompressedNavmeshBounds
{
public:
    BSCompressedNavmeshBounds();

    NiPoint3 minBound;
    NiPoint3 maxBound;
    std::uint64_t unk18;
    std::uint64_t unk20;
    std::uint16_t unk28;
};

static_assert(offsetof(BSCompressedNavmeshBounds, maxBound) == 0x0C, "maxBound offset");
static_assert(offsetof(BSCompressedNavmeshBounds, unk18) == 0x18, "unk18 offset");
static_assert(offsetof(BSCompressedNavmeshBounds, unk28) == 0x28, "unk28 offset");
