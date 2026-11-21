// Source exposure: binary-analysis of the pinned image.
// Code origin: original; the listing only
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf1243c30: GUESS(low)
#pragma once

void operator delete(void*, unsigned __int64) noexcept;

class DeletingLeaf1243c30
{
public:
    virtual ~DeletingLeaf1243c30() {}

    unsigned char storage[0x30];
};
static_assert(sizeof(DeletingLeaf1243c30) == 0x38, "observed sized deletion argument");
