// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// g_contextTag_tls_0x768, ScopedContextTag1e08e0, SubPayload1e08e0, ListEntry1e08e0, Unit1e08e0, RemoveAndDeleteEntry1e08e0, saved, unk00, payload, items, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern __declspec(thread) std::uint32_t g_contextTag_tls_0x768;

struct ScopedContextTag1e08e0
{
    explicit ScopedContextTag1e08e0(std::uint32_t a_tag)
        : saved(g_contextTag_tls_0x768)
    {
        g_contextTag_tls_0x768 = a_tag;
    }

    ~ScopedContextTag1e08e0()
    {
        g_contextTag_tls_0x768 = saved;
    }

    std::uint32_t saved;
};

struct SubPayload1e08e0
{
    std::uint8_t unk00[0x18];  // 00
};
static_assert(sizeof(SubPayload1e08e0) == 0x18, "SubPayload1e08e0 size");

struct ListEntry1e08e0
{
    std::uint8_t unk00[0x10];   // 00
    SubPayload1e08e0* payload;  // 10
};
static_assert(sizeof(ListEntry1e08e0) == 0x18, "ListEntry1e08e0 size");
static_assert(offsetof(ListEntry1e08e0, payload) == 0x10, "ListEntry1e08e0::payload offset");

struct Unit1e08e0
{
    std::uint64_t unk00;      // 00
    ListEntry1e08e0** items;  // 08
    std::uint32_t count;      // 10

    void RemoveAndDeleteEntry1e08e0(ListEntry1e08e0* a_entry);  // compared: 0x1e08e0
};
static_assert(offsetof(Unit1e08e0, items) == 0x08, "Unit1e08e0::items offset");
static_assert(offsetof(Unit1e08e0, count) == 0x10, "Unit1e08e0::count offset");
