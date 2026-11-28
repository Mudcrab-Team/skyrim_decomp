// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ListEntry1efe00, ListNode1efe00, Unit1efe00, FindMaxScore1efe00, object, score, item, next, unk00, head: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ListEntry1efe00
{
    void* object;         // 00
    std::int32_t score;   // 08
};
static_assert(offsetof(ListEntry1efe00, score) == 0x08, "ListEntry1efe00::score offset");

struct ListNode1efe00
{
    ListEntry1efe00* item;  // 00
    ListNode1efe00* next;   // 08
};

struct Unit1efe00
{
    std::uint64_t unk00;  // 00
    ListNode1efe00 head;  // 08

    std::int32_t FindMaxScore1efe00(void** a_outObject, bool (*a_filter)(void*, void*), void* a_userData) const;  // compared: 0x1efe00
};
static_assert(offsetof(Unit1efe00, head) == 0x08, "Unit1efe00::head offset");
