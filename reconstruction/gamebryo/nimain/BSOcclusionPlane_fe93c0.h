// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout following the observed corner and plane accesses.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSOcclusionPlane, NiFrustumPlanes: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// PortalVertex, PortalClipPlane, AreVerticesInsideActivePlanes, Refresh: GUESS(low)
#pragma once

#include <cstdint>

struct PortalVertex
{
    float x;
    float y;
    float z;
};

struct PortalClipPlane
{
    PortalVertex normal;
    float constant;
};

struct NiFrustumPlanes
{
    PortalClipPlane planes[6];
    std::uint32_t activePlanes;
};

class BSOcclusionPlane
{
public:
    bool AreVerticesInsideActivePlanes(const NiFrustumPlanes* frustum);

private:
    void Refresh();

    std::uint8_t unknown00[0xc0];
    PortalVertex vertices[4];
};
