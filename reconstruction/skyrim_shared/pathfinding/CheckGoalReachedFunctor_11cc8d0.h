// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// CheckGoalReachedFunctor: EXE_RTTI
// Func1_1410BA7F0: CRASHLOGGER_PDB(59818@2026.10.24)
// GoalState11cc8d0, GoalPath11cc8d0, GoalMetric11cc8d0, GoalContext11cc8d0, GetMetric, unk00, unk08, unk18, unk20, unk28, unk40, unk83, unkA0, kThreshold11cc8d0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct GoalState11cc8d0
{
    std::uint8_t unk00[0x83];  // 00
    std::uint8_t unk83;        // 83
};

struct GoalPath11cc8d0
{
    std::uint8_t  unk00[0xA0];  // 00
    std::uint32_t unkA0;        // A0
};

class GoalMetric11cc8d0
{
public:
    virtual ~GoalMetric11cc8d0();
    virtual void  Unk_01();
    virtual void  Unk_02();
    virtual void  Unk_03();
    virtual void  Unk_04();
    virtual float GetMetric();  // 28
};

struct GoalContext11cc8d0
{
    std::uint8_t      unk00[0x18];  // 00
    GoalState11cc8d0* unk18;        // 18
    GoalPath11cc8d0*  unk20;        // 20
    GoalMetric11cc8d0* unk28;       // 28
    std::uint8_t      unk30[0x10];  // 30
    float             unk40;        // 40
};

class CheckGoalReachedFunctor
{
public:
    virtual ~CheckGoalReachedFunctor();
    virtual bool Func1_1410BA7F0(GoalContext11cc8d0* context);

    static const float kThreshold11cc8d0;

    float         unk08;  // 08
    std::uint32_t unk0C;  // 0C
};
static_assert(sizeof(CheckGoalReachedFunctor) == 0x10, "CheckGoalReachedFunctor size");
