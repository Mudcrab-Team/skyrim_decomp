// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/Pathfind.cpp:136
// Pathing, Pathing::ComputeLowPathDistance, Pathing::BuildLowPath, BSPathingLocation, TeleportPath, TeleportPath::ComputeLength, BSPathing::DOOR_LOCK_DISPOSITION_IGNORELOCKS: SIBLING(fo4-private@1b765c70, author-permission); stand-ins reduced to what the body uses
// unk00: GUESS(low); the path object is sized only as far as the frame needs
#pragma once

#include <cstdint>

class BSPathingLocation
{
};

namespace BSPathing
{
    enum DOOR_LOCK_DISPOSITION
    {
        DOOR_LOCK_DISPOSITION_IGNORELOCKS = 1
    };
}

class TeleportPath
{
public:
    TeleportPath();
    ~TeleportPath();
    float ComputeLength();

    std::uint8_t unk00[0x50];
};

class Pathing
{
public:
    bool ComputeLowPathDistance(BSPathingLocation& aStartLocation, BSPathingLocation& aGoalLocation, float* apReturnDistance);
    bool BuildLowPath(BSPathingLocation& aStartLocation, BSPathingLocation& aGoalLocation, TeleportPath* apPath, void* apFilter, BSPathing::DOOR_LOCK_DISPOSITION aeDisposition, bool abFlag);
};
