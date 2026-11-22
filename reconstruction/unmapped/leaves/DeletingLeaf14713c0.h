// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf14713c0: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf14713c0
{
public:
    virtual ~DeletingLeaf14713c0() {}

    unsigned char storage[0x78030];
};
static_assert(sizeof(DeletingLeaf14713c0) == 0x78038, "observed sized deletion argument");
