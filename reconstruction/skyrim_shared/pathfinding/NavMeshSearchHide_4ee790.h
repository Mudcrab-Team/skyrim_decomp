// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NavMeshSearchHide, NavMeshSearchHide::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// NavMeshSearchBase, unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class NavMeshSearchBase
{
public:
    virtual ~NavMeshSearchBase();

    std::uint8_t unk08[0x200];  // 08
};
static_assert(sizeof(NavMeshSearchBase) == 0x208, "NavMeshSearchBase size");

class NavMeshSearchHide : public NavMeshSearchBase
{
public:
    NavMeshSearchHide();
    ~NavMeshSearchHide() override;  // compared: 0x4ee790
};
static_assert(sizeof(NavMeshSearchHide) == 0x208, "NavMeshSearchHide size");
