// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Builders/PathBuilderFlight.cpp:52
// PathBuilderFlight, PathBuilderFlight::ValidateFlightPathLocation, PathBuilderFlight::GetMaximumHeightAtLocation, PathingRequestFly, NiPoint3: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// x, y, z: GUESS(low); the point members, only z is read
#pragma once

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class PathingRequestFly;

class PathBuilderFlight
{
public:
    static bool ValidateFlightPathLocation(const PathingRequestFly& arRequest, NiPoint3& arLocation, float afRadius);
    static void GetMaximumHeightAtLocation(const PathingRequestFly& arRequest, const NiPoint3& arLocation, float afRadius, float& arHeight);
};
