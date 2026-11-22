// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf14c8830: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf14c8830
{
public:
    virtual ~DeletingLeaf14c8830() {}

    unsigned char storage[0x818];
};
static_assert(sizeof(DeletingLeaf14c8830) == 0x820, "observed sized deletion argument");
