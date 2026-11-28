// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// ListEntry1efd70, ListNode1efd70, Unit1efd70, FindMinScore1efd70, object, score, item, next, unk00, head: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct ListEntry1efd70
{
    void* object;         // 00
    std::int32_t score;   // 08
};
static_assert(offsetof(ListEntry1efd70, score) == 0x08, "ListEntry1efd70::score offset");

struct ListNode1efd70
{
    ListEntry1efd70* item;  // 00
    ListNode1efd70* next;   // 08
};

struct Unit1efd70
{
    std::uint64_t unk00;  // 00
    ListNode1efd70 head;  // 08

    std::int32_t FindMinScore1efd70(void** a_outObject, bool (*a_filter)(void*, void*), void* a_userData) const;  // compared: 0x1efd70
};
static_assert(offsetof(Unit1efd70, head) == 0x08, "Unit1efd70::head offset");
