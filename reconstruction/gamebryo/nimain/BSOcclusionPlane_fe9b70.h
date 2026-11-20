// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout for the observed endpoint groups.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSOcclusionPlane: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Functionfe9b70, endpoint00, endpoint01, endpoint02, endpoint03: GUESS(low)
#pragma once

#include <cstdint>

class BSOcclusionPlane
{
public:
    std::uint32_t Functionfe9b70() const;

private:
    std::uint8_t unknown00[0xf8];
    const void* endpoint00;
    const void* endpoint01;
    const void* endpoint02;
    const void* endpoint03;
};
