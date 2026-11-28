// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Member1c6930, Holder1c6930, Obj1c6930, Release: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Member1c6930
{
    void Release();
};

struct Holder1c6930
{
    ~Holder1c6930()
    {
        ptr->Release();
    }

    Member1c6930* ptr;  // 00
};

struct Obj1c6930
{
    virtual ~Obj1c6930();  // compared: 0x1c6930

    Holder1c6930 member08;  // 08
};
