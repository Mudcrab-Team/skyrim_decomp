// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// PackageLocation, PackageLocation::dtor_140443050: CRASHLOGGER_PDB(59818@2026.10.24)
// PackageLocationBase, locType, radius, data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

class PackageLocationBase
{
public:
    virtual ~PackageLocationBase() {}
};
static_assert(sizeof(PackageLocationBase) == 0x08, "PackageLocationBase size");

class PackageLocation : public PackageLocationBase
{
public:
    PackageLocation();
    ~PackageLocation() override;  // compared: 0x4a5600

    std::int8_t locType;  // 08
    std::uint32_t radius;  // 0C
    void* data;  // 10
};
static_assert(sizeof(PackageLocation) == 0x18, "PackageLocation size");
