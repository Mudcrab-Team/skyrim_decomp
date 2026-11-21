// Source exposure: mixed (community declarations; the pinned image listing).
// Code origin: original; the listing and community names only
// NiBSplineFloatInterpolator: EXE_RTTI
// IsFloatValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiBSplineFloatInterpolator::controlHandle: GUESS(low); a stored handle read for channel 0, named for its use
// every member named unknownNN: GUESS(low); the compared bodies read none of them
#pragma once

#include <cstdint>

class NiBSplineFloatInterpolator
{
public:
    virtual std::uint8_t IsFloatValueSupported() const;
    std::uint32_t Functionf7a870(std::uint16_t a_channel) const;
    std::uint32_t Functionf7a8c0(std::uint16_t a_channel) const;

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint32_t unknown30;  // 30
    std::uint32_t controlHandle;  // 34
};
