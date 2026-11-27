// Source exposure: mixed.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// PackageLocation: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PackageLocation::Function4a3480: GUESS(low)
// PackageLocation::unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class PackageLocation
{
public:
    std::int32_t Function4a3480();
    std::uint8_t unknown00[8];
    std::int8_t unk08;
};
static_assert(offsetof(PackageLocation, unk08) == 8, "field offset");
