// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7a9290 (skyrim/ai/movement/MovementPlannerAgentWarp_7a9290): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x1222300 Owner1222300::Function1222300
#include "Owner1222300.h"

// guess: same compiled code as matched 0x7a9290 apart from relocated fields; its role here is not established.
void Owner1222300::Function1222300()
{
    if (planner) {
        planner->RemoveListener(&kInterfaceId);
        planner = nullptr;
    }
}
