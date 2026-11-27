// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PackageLocation: STANDIN GUESS(low)
// PackageLocation::Function4a3670: GUESS(low)
// PackageLocation::tag, PackageLocation::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class PackageLocation
{
public:
    std::uint32_t Function4a3670();
    std::uint8_t unknown0[8];
    std::uint8_t tag;
    std::uint8_t unknown9[7];
    std::uint32_t value;
};
static_assert(offsetof(PackageLocation, tag) == 8, "field offset");
static_assert(offsetof(PackageLocation, value) == 16, "field offset");
