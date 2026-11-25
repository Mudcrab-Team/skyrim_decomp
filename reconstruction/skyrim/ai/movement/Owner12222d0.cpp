// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7a9260 (skyrim/ai/movement/MovementPlannerAgentWarp_7a9260): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x12222d0 Owner12222d0::Function12222d0
#include "Owner12222d0.h"

// guess: same compiled code as matched 0x7a9260 apart from relocated fields; its role here is not established.
void Owner12222d0::Function12222d0(PlannerInterface* a_interface)
{
    planner = a_interface;
    a_interface->AddListener(&kInterfaceId, &listener);
}
