// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// RefTarget1c7b40, Base1c7b40, Obj1c7b40, Init: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

struct RefTarget1c7b40
{
    void IncRef()
    {
        long cur = refCount10;
        long prev;
        do {
            prev = cur;
            // atomic packed upper-bit reference count increment
            cur = _InterlockedCompareExchange(&refCount10, cur + 0x1000, prev);
        } while (cur != prev);
    }

    std::uint8_t unk00[0x10];  // 00
    long refCount10;           // 10
};

struct Base1c7b40
{
    void InitBase(void* a_arg);

    void* ptr00;  // 00
};

struct Obj1c7b40 : Base1c7b40
{
    void Init(void* a_arg1, void* a_arg2, RefTarget1c7b40* const& a_target);  // compared: 0x1c7b40

    RefTarget1c7b40* target08;  // 08
    void* arg10;                // 10
};
