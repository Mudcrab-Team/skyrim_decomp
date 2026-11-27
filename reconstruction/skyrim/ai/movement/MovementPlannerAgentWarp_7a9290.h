// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MovementPlannerAgentWarp, MovementPlannerAgentWarp::ClearInterface, MovementPlannerAgentWarp::planner: GUESS(low)
// PlannerInterface, PlannerInterface::RemoveListener, kInterfaceId, InterfaceId: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <cstddef>

struct InterfaceId
{
    std::uint64_t unk00;
};

extern const InterfaceId kInterfaceId;

class PlannerInterface
{
public:
    virtual ~PlannerInterface();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void RemoveListener(const InterfaceId* a_id);  // 04
};

class MovementPlannerAgentWarp
{
public:
    void ClearInterface();  // compared: 0x7a9290

    std::uint8_t pad00[0xA8];
    PlannerInterface* planner;  // 0A8
};
