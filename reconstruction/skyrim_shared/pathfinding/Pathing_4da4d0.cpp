// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4da4d0 Pathing::ComputeLowPathDistance
// Adapted bodies: Pathing::ComputeLowPathDistance follows fo4-private@1b765c70 src/Shared/Pathfinding/Pathing/Pathfind.cpp:136
#include "Pathing_4da4d0.h"

bool Pathing::ComputeLowPathDistance(BSPathingLocation& aStartLocation, BSPathingLocation& aGoalLocation, float* apReturnDistance)
{
    TeleportPath tp;
    if (BuildLowPath(aStartLocation, aGoalLocation, &tp, 0, BSPathing::DOOR_LOCK_DISPOSITION_IGNORELOCKS, true))
    {
        *apReturnDistance = tp.ComputeLength();
        return true;
    }
    else
    {
        *apReturnDistance = 0.0f;
        return false;
    }
}
