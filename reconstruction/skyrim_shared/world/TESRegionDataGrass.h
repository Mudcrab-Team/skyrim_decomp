// Source exposure: mixed (local binary analysis and public names).
// Code origin: original reconstruction; body written from the listing.
// SPDX-License-Identifier: CC0-1.0
// TESRegionDataGrass: EXE_RTTI
// IsLoaded: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Function250620, padding, member: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionDataGrass
{
public:
    virtual std::uint8_t IsLoaded() const;
    void* Function250620() const;

    std::uint8_t padding[0x8];  // 08
    void*        member;        // 10
};
