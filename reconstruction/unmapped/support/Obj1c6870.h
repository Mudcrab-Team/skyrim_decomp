// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Member1c6870, Obj1c6870, Release: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Member1c6870
{
    void Release();
};

struct Obj1c6870
{
    virtual ~Obj1c6870();  // compared: 0x1c6870

    Member1c6870* member08;  // 08
};
