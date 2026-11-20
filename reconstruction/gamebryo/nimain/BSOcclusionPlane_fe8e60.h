// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original partial layout from the observed aperture test.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSOcclusionPlane, NiFrustumPlanes, NiPoint3: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IntersectsFrustum, Refresh, IntersectsQuad, corners, edgeFlags: GUESS(low)
#pragma once

#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct NiFrustumPlanes
{
    bool IntersectsQuad(const NiPoint3* corners, bool* edgeFlags) const;
};

class BSOcclusionPlane
{
public:
    bool IntersectsFrustum(const NiFrustumPlanes* frustum, bool testOrigin, const NiPoint3& origin);

private:
    void Refresh();

    std::uint8_t unknown00[0x10];
    NiPoint3 translation;
    std::uint8_t unknown1C[0xc];
    NiPoint3 horizontal;
    NiPoint3 vertical;
    std::uint8_t unknown40[8];
    float halfWidth;
    float halfHeight;
    std::uint8_t unknown50[0x70];
    NiPoint3 corners[4];
    bool edgeFlags[4];
};
