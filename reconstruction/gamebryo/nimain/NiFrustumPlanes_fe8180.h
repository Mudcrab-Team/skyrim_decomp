// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layout of the plane-set initializer used by the box.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// NiPlane, NiFrustumPlanes, activePlanes, basePlaneStates: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>

class NiPlane
{
public:
    NiPlane();

private:
    std::uint8_t unknown00[0x10];
};

class NiFrustumPlanes
{
public:
    NiFrustumPlanes();

private:
    NiPlane planes[6];
    std::uint32_t activePlanes;
    std::uint32_t basePlaneStates;
};

