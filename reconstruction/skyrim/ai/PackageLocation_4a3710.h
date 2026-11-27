// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PackageLocation: STANDIN GUESS(low)
// PackageLocation::Function4a3710: GUESS(low)
// PackageLocation::unknown0, PackageLocation::tag, PackageLocation::unknown9, PackageLocation::storedValue: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class PackageLocation
{
public:
    void Function4a3710(void* value);
    std::uint8_t unknown0[8];
    std::uint8_t tag;
    std::uint8_t unknown9[7];
    void* storedValue;
};
static_assert(offsetof(PackageLocation, tag) == 8, "field offset");
static_assert(offsetof(PackageLocation, storedValue) == 16, "field offset");
