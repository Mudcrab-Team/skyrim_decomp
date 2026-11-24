// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// CheckStoppedMovingFunctor, ICheckEndReachedFunctor: EXE_RTTI
// ICheckEndReachedFunctor: STANDIN EXE_RTTI; only its out-of-line destructor is declared
#pragma once

struct ICheckEndReachedFunctor
{
public:
    ICheckEndReachedFunctor();
    virtual ~ICheckEndReachedFunctor();
};

struct CheckStoppedMovingFunctor : public ICheckEndReachedFunctor
{
public:
    CheckStoppedMovingFunctor();
    ~CheckStoppedMovingFunctor() override {}

};
static_assert(sizeof(CheckStoppedMovingFunctor) == 0x8, "CheckStoppedMovingFunctor size from the deleting destructor");
