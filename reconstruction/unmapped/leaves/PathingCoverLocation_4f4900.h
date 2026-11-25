// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestCover.cpp:111
// PathingCoverLocation, SetCoverData, cCoverHeight, bStandCover, bHigherThanCrouch, bLeftEdgeOpen, bRightEdgeOpen, cEdge, cState: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// PathingCoverLocation, SetCoverData: CRASHLOGGER_PDB(59818@2026.10.24)
// unk00: GUESS(low)
#pragma once

#include <cstdint>

class PathingCoverLocation
{
public:
    void SetCoverData(std::uint16_t a_cover, std::uint16_t a_stand, std::uint16_t a_crouch, bool a_left, bool a_right, std::uint8_t a_edge);  // compared: 0x4f4900

    std::uint8_t unk00[0x5C];
    std::uint8_t cCoverHeight;  // 5C
    bool bStandCover;           // 5D
    bool bHigherThanCrouch;     // 5E
    bool bLeftEdgeOpen;         // 5F
    bool bRightEdgeOpen;        // 60
    std::uint8_t cEdge;         // 61
    std::uint8_t cState;        // 62
};
