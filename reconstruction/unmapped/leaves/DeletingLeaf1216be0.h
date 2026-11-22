// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf1216be0: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf1216be0
{
public:
    virtual ~DeletingLeaf1216be0() {}

    unsigned char storage[0x18];
};
static_assert(sizeof(DeletingLeaf1216be0) == 0x20, "observed sized deletion argument");
