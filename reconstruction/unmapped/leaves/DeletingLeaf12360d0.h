// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf12360d0: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf12360d0
{
public:
    virtual ~DeletingLeaf12360d0() {}

    unsigned char storage[0x28];
};
static_assert(sizeof(DeletingLeaf12360d0) == 0x30, "observed sized deletion argument");
