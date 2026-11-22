// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf14dc8d0: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf14dc8d0
{
public:
    virtual ~DeletingLeaf14dc8d0() {}

    unsigned char storage[0x18];
};
static_assert(sizeof(DeletingLeaf14dc8d0) == 0x20, "observed sized deletion argument");
