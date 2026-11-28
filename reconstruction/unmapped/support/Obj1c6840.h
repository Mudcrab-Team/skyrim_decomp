// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Member1c6840, Obj1c6840, Release: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Member1c6840
{
    void Release();
};

struct Obj1c6840
{
    virtual ~Obj1c6840();  // compared: 0x1c6840

    Member1c6840* member08;  // 08
};
