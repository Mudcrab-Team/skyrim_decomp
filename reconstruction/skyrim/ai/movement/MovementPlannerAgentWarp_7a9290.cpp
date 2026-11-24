// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7a9290 MovementPlannerAgentWarp::ClearInterface
// Adapted bodies: none
#include "MovementPlannerAgentWarp_7a9290.h"

void MovementPlannerAgentWarp::ClearInterface()
{
    if (planner) {
        planner->RemoveListener(&kInterfaceId);
        planner = nullptr;
    }
}
