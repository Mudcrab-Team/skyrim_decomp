// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4f4900 PathingCoverLocation::SetCoverData
// Adapted bodies: PathingCoverLocation::SetCoverData from the sibling source named in the header
#include "PathingCoverLocation_4f4900.h"

void PathingCoverLocation::SetCoverData(std::uint16_t a_cover, std::uint16_t a_stand, std::uint16_t a_crouch, bool a_left, bool a_right, std::uint8_t a_edge)
{
    cCoverHeight = static_cast<std::uint8_t>(a_cover);
    cState = 0;
    bStandCover = a_cover >= a_stand;
    bHigherThanCrouch = a_cover > a_crouch;
    bLeftEdgeOpen = a_left;
    bRightEdgeOpen = a_right;
    cEdge = a_edge;
}
