// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NavMeshSearchMaxCost, NavMeshSearchMaxCost::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// NavMeshSearchBase, unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class NavMeshSearchBase
{
public:
    virtual ~NavMeshSearchBase();

    std::uint8_t unk08[0x1C8];  // 08
};
static_assert(sizeof(NavMeshSearchBase) == 0x1D0, "NavMeshSearchBase size");

class NavMeshSearchMaxCost : public NavMeshSearchBase
{
public:
    NavMeshSearchMaxCost();
    ~NavMeshSearchMaxCost() override;  // compared: 0x4f09a0
};
static_assert(sizeof(NavMeshSearchMaxCost) == 0x1D0, "NavMeshSearchMaxCost size");
