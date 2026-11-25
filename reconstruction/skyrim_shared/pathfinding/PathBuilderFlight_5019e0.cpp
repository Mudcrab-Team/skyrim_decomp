// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x5019e0 PathBuilderFlight::ValidateFlightPathLocation
// Adapted bodies: PathBuilderFlight::ValidateFlightPathLocation follows fo4-private@1b765c70 src/Shared/Pathfinding/Builders/PathBuilderFlight.cpp:52
#include "PathBuilderFlight_5019e0.h"

#include <cfloat>

bool PathBuilderFlight::ValidateFlightPathLocation(const PathingRequestFly& arRequest, NiPoint3& arLocation, float afRadius)
{
    float fNewHeight = -FLT_MAX;
    GetMaximumHeightAtLocation(arRequest, arLocation, afRadius, fNewHeight);
    if (fNewHeight + afRadius > arLocation.z)
    {
        arLocation.z = fNewHeight + afRadius;
        return true;
    }
    return false;
}
