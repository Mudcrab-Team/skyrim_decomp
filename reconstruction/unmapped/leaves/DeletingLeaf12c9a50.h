// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf12c9a50: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf12c9a50
{
public:
    virtual ~DeletingLeaf12c9a50() {}

    unsigned char storage[0x20];
};
static_assert(sizeof(DeletingLeaf12c9a50) == 0x28, "observed sized deletion argument");
