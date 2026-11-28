// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TESFileContainer, TESFileContainer::GetMaster: CRASHLOGGER_PDB(59818@2026.10.24)
// TESFile1e2bb0, TESFileArray1e2bb0, IsMaster, data, size, array: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESFile1e2bb0
{
public:
    bool IsMaster() const;
};

struct TESFileArray1e2bb0
{
    TESFile1e2bb0** data;  // 00
    std::uint32_t   size;  // 08
};
static_assert(offsetof(TESFileArray1e2bb0, size) == 0x08, "size offset");

class TESFileContainer
{
public:
    TESFile1e2bb0* GetMaster(bool a_firstOnly) const;  // compared: 0x1e2bb0

    TESFileArray1e2bb0* array;  // 00
};
static_assert(offsetof(TESFileContainer, array) == 0x00, "array offset");
