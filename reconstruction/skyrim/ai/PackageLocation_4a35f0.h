// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// PackageLocation: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PackageLocation::Function4a35f0: GUESS(low)
// PackageLocation::unknown0, PackageLocation::tag, PackageLocation::unknown9, PackageLocation::value: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>



class PackageLocation
{
public:
    void* Function4a35f0();
    std::uint8_t unknown0[8];
    std::uint8_t tag;
    std::uint8_t unknown9[7];
    void* value;
};
static_assert(offsetof(PackageLocation, tag) == 8, "field offset");
static_assert(offsetof(PackageLocation, value) == 16, "field offset");
