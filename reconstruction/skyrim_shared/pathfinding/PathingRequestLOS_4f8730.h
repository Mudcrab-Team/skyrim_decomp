// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PathingRequestLOS, PathingRequestLOS::target, RefTarget: GUESS(low); RefTarget is a stand-in for a refcounted object
#pragma once

#include <cstdint>
#include <cstddef>

// RefTarget::refCount, RefTarget::~RefTarget: GUESS(low)
class RefTarget
{
public:
    virtual ~RefTarget();
    std::uint8_t pad08[0x78];
    volatile long refCount;  // 0x80
};

class PathingRequestLOS
{
public:
    ~PathingRequestLOS();  // compared: 0x4f8730

    RefTarget* target;  // 0x00
};
