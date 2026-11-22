// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf12c9960: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf12c9960
{
public:
    virtual ~DeletingLeaf12c9960() {}

    unsigned char storage[0x18];
};
static_assert(sizeof(DeletingLeaf12c9960) == 0x20, "observed sized deletion argument");
