// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x7a9260 (skyrim/ai/movement/MovementPlannerAgentWarp_7a9260): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// PlannerInterface, ListenerBase: GUESS(low) STANDIN
// Function12222d0, Owner12222d0: GUESS(low) STANDIN
#pragma once
#include "MovementPlannerAgentWarp_7a9260.h"

class Owner12222d0
{
public:
    void Function12222d0(PlannerInterface* a_interface);

    std::uint8_t pad00[0x20];
    ListenerBase listener;  // 020
    std::uint8_t pad28[0xA8 - 0x28];
    PlannerInterface* planner;  // 0A8
};

