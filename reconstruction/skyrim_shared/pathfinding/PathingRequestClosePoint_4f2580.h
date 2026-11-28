// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// PathingRequestClosePoint, PathingRequestClosePoint::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingRequestBase, ClosePointTarget, target: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

struct ClosePointTarget
{
    ~ClosePointTarget();

    std::uint8_t unk00[0x40];  // 00
};
static_assert(sizeof(ClosePointTarget) == 0x40, "ClosePointTarget size");

class PathingRequestBase
{
public:
    virtual ~PathingRequestBase();

    std::uint8_t unk08[0xF8];  // 08
};
static_assert(sizeof(PathingRequestBase) == 0x100, "PathingRequestBase size");

class PathingRequestClosePoint : public PathingRequestBase
{
public:
    PathingRequestClosePoint();

    ClosePointTarget target;  // 100
};
static_assert(sizeof(PathingRequestClosePoint) == 0x140, "PathingRequestClosePoint size");
