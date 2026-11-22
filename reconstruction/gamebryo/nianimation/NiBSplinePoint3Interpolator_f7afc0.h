// Source exposure: mixed (community declarations; the pinned image listing).
// Code origin: original; the listing and community names only
// NiBSplinePoint3Interpolator: EXE_RTTI
// IsPoint3ValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class NiBSplinePoint3Interpolator
{
public:
    virtual std::uint8_t IsPoint3ValueSupported() const;
    std::uint32_t Functionf7afc0(std::uint16_t a_channel) const;
    std::uint32_t Functionf7afe0(std::uint16_t a_channel) const;
};
