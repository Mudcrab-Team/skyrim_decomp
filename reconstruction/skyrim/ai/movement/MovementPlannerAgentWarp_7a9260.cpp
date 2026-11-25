// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7a9260 MovementPlannerAgentWarp::SetInterface
// Adapted bodies: none
#include "MovementPlannerAgentWarp_7a9260.h"

void MovementPlannerAgentWarp::SetInterface(PlannerInterface* a_interface)
{
    planner = a_interface;
    a_interface->AddListener(&kInterfaceId, &listener);
}
