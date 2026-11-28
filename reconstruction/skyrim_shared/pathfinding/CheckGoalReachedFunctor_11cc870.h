// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// CheckGoalReachedFunctor, ICheckEndReachedFunctor: EXE_RTTI
// unk08: GUESS(low)
#pragma once

#include <cstdint>

class ICheckEndReachedFunctor
{
public:
    ICheckEndReachedFunctor();
    virtual ~ICheckEndReachedFunctor();
};
static_assert(sizeof(ICheckEndReachedFunctor) == 0x8, "ICheckEndReachedFunctor size");

class CheckGoalReachedFunctor : public ICheckEndReachedFunctor
{
public:
    CheckGoalReachedFunctor();
    ~CheckGoalReachedFunctor() override;

    std::uint32_t unk08;  // 08
    std::uint32_t unk0C;  // 0C
};
static_assert(sizeof(CheckGoalReachedFunctor) == 0x10, "CheckGoalReachedFunctor size");
