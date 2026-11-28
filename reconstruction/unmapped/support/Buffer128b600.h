// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FreeFn_128b600, InnerBuffer_128b600, OuterBuffer_128b600, Buffer128b600, g_allocReady_128b600, g_freeFn_128b600, Clear, begin, end, cap, inner, extra, primary, unk18, secondary: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

using FreeFn_128b600 = void (*)(void*);

extern std::uint64_t g_allocReady_128b600;
extern FreeFn_128b600 g_freeFn_128b600;

struct InnerBuffer_128b600
{
    void* begin;  // 0x00
    void* end;    // 0x08
    void* cap;    // 0x10

    void Clear()
    {
        if (begin != end) {
            end = begin;
        }
    }

    ~InnerBuffer_128b600()
    {
        if (begin != nullptr) {
            if (g_allocReady_128b600 != 0 && g_freeFn_128b600 != nullptr) {
                g_freeFn_128b600(begin);
            }
            begin = nullptr;
            end = nullptr;
            cap = nullptr;
        }
    }
};

struct OuterBuffer_128b600
{
    InnerBuffer_128b600 inner;  // 0x00
    void* extra;                // 0x18

    ~OuterBuffer_128b600()
    {
        inner.Clear();
        extra = nullptr;
    }
};
static_assert(sizeof(OuterBuffer_128b600) == 0x20, "OuterBuffer_128b600 size");

struct Buffer128b600
{
    InnerBuffer_128b600 primary;    // 0x0000
    std::uint8_t unk18[0x1008];     // 0x0018
    OuterBuffer_128b600 secondary;  // 0x1020

    ~Buffer128b600();
};
static_assert(offsetof(Buffer128b600, secondary) == 0x1020, "secondary offset");
