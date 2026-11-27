// Source exposure: mixed.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// PatrolActorPackageData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// PatrolActorPackageData::Function7bc510: GUESS(low)
// PatrolActorPackageData::unk28: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class PatrolActorPackageData
{
public:
    bool Function7bc510();
    std::uint8_t unknown00[40];
    std::uint32_t unk28;
};
static_assert(offsetof(PatrolActorPackageData, unk28) == 40, "field offset");
