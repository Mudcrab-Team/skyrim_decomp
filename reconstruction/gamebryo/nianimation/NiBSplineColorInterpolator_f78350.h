// Source exposure: mixed (community declarations; the pinned image listing).
// Code origin: original; the listing and community names only
// NiBSplineColorInterpolator: EXE_RTTI
// IsColorAValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

class NiBSplineColorInterpolator
{
public:
    virtual std::uint8_t IsColorAValueSupported() const;
    std::uint32_t Functionf78350(std::uint16_t a_channel) const;
    std::uint32_t Functionf78370(std::uint16_t a_channel) const;
};
