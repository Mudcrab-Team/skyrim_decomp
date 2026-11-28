// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Member1c6900, Holder1c6900, Obj1c6900, Release: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Member1c6900
{
    void Release();
};

struct Holder1c6900
{
    ~Holder1c6900()
    {
        ptr->Release();
    }

    Member1c6900* ptr;  // 00
};

struct Obj1c6900
{
    virtual ~Obj1c6900();  // compared: 0x1c6900

    Holder1c6900 member08;  // 08
};
