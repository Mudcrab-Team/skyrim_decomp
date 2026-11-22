// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf11f0210: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf11f0210
{
public:
    virtual ~DeletingLeaf11f0210() {}

    unsigned char storage[0x18];
};
static_assert(sizeof(DeletingLeaf11f0210) == 0x20, "observed sized deletion argument");
