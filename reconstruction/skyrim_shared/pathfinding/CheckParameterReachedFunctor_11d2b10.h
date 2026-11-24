// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// CheckParameterReachedFunctor, ICheckEndReachedFunctor: EXE_RTTI
// ICheckEndReachedFunctor: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

struct ICheckEndReachedFunctor
{
public:
    ICheckEndReachedFunctor();
    virtual ~ICheckEndReachedFunctor();
};

struct CheckParameterReachedFunctor : public ICheckEndReachedFunctor
{
public:
    CheckParameterReachedFunctor();
    ~CheckParameterReachedFunctor() override {}

    char unk08[0x8];
};
static_assert(sizeof(CheckParameterReachedFunctor) == 0x10, "CheckParameterReachedFunctor size from the deleting destructor");
