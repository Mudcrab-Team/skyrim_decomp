// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// MovementMessageWarpToLocation, MovementMessageWarpToLocation::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementMessageBase, WarpLocationMember, refCount, location: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

struct WarpLocationMember
{
    ~WarpLocationMember();

    std::uint8_t unk00[0x40];  // 00
};
static_assert(sizeof(WarpLocationMember) == 0x40, "WarpLocationMember size");

class MovementMessageBase
{
public:
    virtual ~MovementMessageBase();

    std::uint32_t refCount;  // 08
};
static_assert(sizeof(MovementMessageBase) == 0x10, "MovementMessageBase size");

class MovementMessageWarpToLocation : public MovementMessageBase
{
public:
    MovementMessageWarpToLocation();
    ~MovementMessageWarpToLocation() override;  // compared: 0x1217df0

    WarpLocationMember location;  // 10
};
static_assert(sizeof(MovementMessageWarpToLocation) == 0x50, "MovementMessageWarpToLocation size");
