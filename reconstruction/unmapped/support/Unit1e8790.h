// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// g_contextTag_tls_0x768, ScopedContextTag1e8790, Payload1e8790, Unit1e8790, DeletePayload1e8790, saved, unk00, payload: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern __declspec(thread) std::uint32_t g_contextTag_tls_0x768;

struct ScopedContextTag1e8790
{
    explicit ScopedContextTag1e8790(std::uint32_t a_tag)
        : saved(g_contextTag_tls_0x768)
    {
        g_contextTag_tls_0x768 = a_tag;
    }

    ~ScopedContextTag1e8790()
    {
        g_contextTag_tls_0x768 = saved;
    }

    std::uint32_t saved;
};

struct Payload1e8790
{
    std::uint8_t unk00[0x18];  // 00
};
static_assert(sizeof(Payload1e8790) == 0x18, "Payload1e8790 size");

struct Unit1e8790
{
    std::uint8_t unk00[0x10];  // 00
    Payload1e8790* payload;    // 10

    void DeletePayload1e8790();  // compared: 0x1e8790
};
static_assert(offsetof(Unit1e8790, payload) == 0x10, "Unit1e8790::payload offset");
