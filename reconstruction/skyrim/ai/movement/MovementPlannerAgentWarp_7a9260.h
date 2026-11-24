// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MovementPlannerAgentWarp, MovementPlannerAgentWarp::SetInterface, MovementPlannerAgentWarp::interface, MovementPlannerAgentWarp::listener: GUESS(low)
// PlannerInterface, PlannerInterface::AddListener, PlannerInterface::unk00, kInterfaceId, ListenerBase: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <cstddef>

struct ListenerBase
{
    std::uint64_t unk00;
};

struct InterfaceId
{
    std::uint64_t unk00;
};

extern const InterfaceId kInterfaceId;

class PlannerInterface
{
public:
    virtual ~PlannerInterface();
    virtual void AddListener(const InterfaceId* a_id, ListenerBase* a_listener);  // 01
};

class MovementPlannerAgentWarp
{
public:
    void SetInterface(PlannerInterface* a_interface);  // compared: 0x7a9260

    std::uint8_t pad00[0x20];
    ListenerBase listener;  // 020
    std::uint8_t pad28[0xA8 - 0x28];
    PlannerInterface* planner;  // 0A8
};
