// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// IMovementPlannerAgent, Func1_141109760: CRASHLOGGER_PDB(59818@2026.10.24)
// PlannerPrimaryBase, PlannerController, PlannerSubAgent, MovementPlannerAgentImpl, CheckState, ApplyValue, controller, subAgent, unk38, Unk_01..Unk_12: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class PlannerController
{
public:
    virtual ~PlannerController();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12();
    virtual bool CheckState(void* context);  // 98
};

class PlannerSubAgent
{
public:
    virtual ~PlannerSubAgent();
    virtual void Unk_01();
    virtual void ApplyValue(std::uint64_t value);  // 10
};

struct PlannerPayload
{
    std::uint64_t unk00[7];  // 00
    std::uint64_t unk38;     // 38
};

class PlannerPrimaryBase
{
public:
    virtual ~PlannerPrimaryBase();

    PlannerController* controller;  // 08
};
static_assert(sizeof(PlannerPrimaryBase) == 0x10, "PlannerPrimaryBase size");

class IMovementPlannerAgent
{
public:
    virtual ~IMovementPlannerAgent();
    virtual void Func1_141109760(void* context, const PlannerPayload* payload);
};

class MovementPlannerAgentImpl : public PlannerPrimaryBase, public IMovementPlannerAgent
{
public:
    void Func1_141109760(void* context, const PlannerPayload* payload) override;

    std::uint64_t   unk18;     // 18
    PlannerSubAgent subAgent;  // 20
};
