// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FreeFn_126dff0, InnerBuffer_126dff0, Buffer126dff0, g_allocReady_126dff0, g_freeFn_126dff0, Clear, begin, end, cap, inner, extra: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

using FreeFn_126dff0 = void (*)(void*);

extern std::uint64_t g_allocReady_126dff0;
extern FreeFn_126dff0 g_freeFn_126dff0;

struct InnerBuffer_126dff0
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

    ~InnerBuffer_126dff0()
    {
        if (begin != nullptr) {
            if (g_allocReady_126dff0 != 0 && g_freeFn_126dff0 != nullptr) {
                g_freeFn_126dff0(begin);
            }
            begin = nullptr;
            end = nullptr;
            cap = nullptr;
        }
    }
};

struct Buffer126dff0
{
    InnerBuffer_126dff0 inner;  // 0x00
    void* extra;                // 0x18

    ~Buffer126dff0();
};
static_assert(sizeof(Buffer126dff0) == 0x20, "Buffer126dff0 size");
