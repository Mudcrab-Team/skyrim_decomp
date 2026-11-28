// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// PathingRequestSafeStraightLine, PathingRequestSafeStraightLine::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingRequestBase, SafeStraightLineData, data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

struct SafeStraightLineData
{
    ~SafeStraightLineData();

    std::uint8_t unk00[0x48];  // 00
};
static_assert(sizeof(SafeStraightLineData) == 0x48, "SafeStraightLineData size");

class PathingRequestBase
{
public:
    virtual ~PathingRequestBase();

    std::uint8_t unk08[0xF8];  // 08
};
static_assert(sizeof(PathingRequestBase) == 0x100, "PathingRequestBase size");

class PathingRequestSafeStraightLine : public PathingRequestBase
{
public:
    PathingRequestSafeStraightLine();

    SafeStraightLineData data;  // 100
};
static_assert(sizeof(PathingRequestSafeStraightLine) == 0x148, "PathingRequestSafeStraightLine size");
