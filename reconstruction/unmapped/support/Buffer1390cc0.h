// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FreeFn_1390cc0, InnerBuffer_1390cc0, Buffer1390cc0, g_allocReady_1390cc0, g_freeFn_1390cc0, Clear, begin, end, cap, inner, extra: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

using FreeFn_1390cc0 = void (*)(void*);

extern std::uint64_t g_allocReady_1390cc0;
extern FreeFn_1390cc0 g_freeFn_1390cc0;

struct InnerBuffer_1390cc0
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

    ~InnerBuffer_1390cc0()
    {
        if (begin != nullptr) {
            if (g_allocReady_1390cc0 != 0 && g_freeFn_1390cc0 != nullptr) {
                g_freeFn_1390cc0(begin);
            }
            begin = nullptr;
            end = nullptr;
            cap = nullptr;
        }
    }
};

struct Buffer1390cc0
{
    InnerBuffer_1390cc0 inner;  // 0x00
    void* extra;                // 0x18

    ~Buffer1390cc0();
};
static_assert(sizeof(Buffer1390cc0) == 0x20, "Buffer1390cc0 size");
