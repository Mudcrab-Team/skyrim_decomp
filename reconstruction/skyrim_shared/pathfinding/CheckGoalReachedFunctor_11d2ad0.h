// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// CheckGoalReachedFunctor, ICheckEndReachedFunctor: EXE_RTTI
// ICheckEndReachedFunctor: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

struct ICheckEndReachedFunctor
{
public:
    ICheckEndReachedFunctor();
    virtual ~ICheckEndReachedFunctor();
};

struct CheckGoalReachedFunctor : public ICheckEndReachedFunctor
{
public:
    CheckGoalReachedFunctor();
    ~CheckGoalReachedFunctor() override {}

    char unk08[0x8];
};
static_assert(sizeof(CheckGoalReachedFunctor) == 0x10, "CheckGoalReachedFunctor size from the deleting destructor");
