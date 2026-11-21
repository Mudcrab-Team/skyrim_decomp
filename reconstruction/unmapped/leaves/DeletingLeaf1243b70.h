// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf1243b70: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf1243b70
{
public:
    virtual ~DeletingLeaf1243b70() {}

    unsigned char storage[0x18];
};
static_assert(sizeof(DeletingLeaf1243b70) == 0x20, "observed sized deletion argument");
