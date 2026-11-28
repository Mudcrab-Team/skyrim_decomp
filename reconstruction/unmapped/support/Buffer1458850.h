// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// FreeFn_1458850, InnerBuffer_1458850, CallbackOwner_1458850, Buffer1458850, g_allocReady_1458850, g_freeFn_1458850, begin, end, cap, ctx, fn, inner, unk18, callback: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

using FreeFn_1458850 = void (*)(void*);

extern std::uint64_t g_allocReady_1458850;
extern FreeFn_1458850 g_freeFn_1458850;

struct InnerBuffer_1458850
{
    void* begin;  // 0x00
    void* end;    // 0x08
    void* cap;    // 0x10

    ~InnerBuffer_1458850()
    {
        if (begin != nullptr) {
            if (g_allocReady_1458850 != 0 && g_freeFn_1458850 != nullptr) {
                g_freeFn_1458850(begin);
            }
            begin = nullptr;
            end = nullptr;
            cap = nullptr;
        }
    }
};

struct CallbackOwner_1458850
{
    void* ctx;          // 0x00
    FreeFn_1458850 fn;  // 0x08

    ~CallbackOwner_1458850()
    {
        if (fn != nullptr) {
            fn(ctx);
        }
        ctx = nullptr;
    }
};

struct Buffer1458850
{
    InnerBuffer_1458850 inner;       // 0x00
    std::uint8_t unk18[0x28];        // 0x18
    CallbackOwner_1458850 callback;  // 0x40

    ~Buffer1458850();
};
static_assert(offsetof(Buffer1458850, callback) == 0x40, "callback offset");
