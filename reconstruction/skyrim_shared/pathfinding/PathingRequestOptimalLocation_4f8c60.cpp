// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x4f8c60 PathingRequestOptimalLocation::CopyTo
// Adapted bodies: PathingRequestOptimalLocation::CopyTo follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp:32
#include "PathingRequestOptimalLocation_4f8c60.h"

void PathingRequestOptimalLocation::CopyTo(BSPathingRequest& destination)
{
    BSPathingRequest::CopyTo(destination);
    auto& request = static_cast<PathingRequestOptimalLocation&>(destination);
    request.fPointHeight = fPointHeight;
    request.m_fUnknownValue2 = m_fUnknownValue2;
    request.m_fUnknownValue3 = m_fUnknownValue3;
    request.m_fUnknownValue4 = m_fUnknownValue4;
}
