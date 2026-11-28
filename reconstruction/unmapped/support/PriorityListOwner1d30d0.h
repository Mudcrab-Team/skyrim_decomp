// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// PriorityEntry1d30d0, PriorityList1d30d0, PriorityListOwner1d30d0, SortByPriority1d30d0, unk00, priority, count, items, list: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct PriorityEntry1d30d0
{
    std::uint8_t unk00;     // 00
    std::uint8_t priority;  // 01
};
static_assert(offsetof(PriorityEntry1d30d0, priority) == 0x01, "PriorityEntry1d30d0::priority offset");

struct PriorityList1d30d0
{
    std::uint32_t unk00;          // 00
    std::uint8_t count;           // 04
    PriorityEntry1d30d0** items;  // 08
};
static_assert(offsetof(PriorityList1d30d0, count) == 0x04, "PriorityList1d30d0::count offset");
static_assert(offsetof(PriorityList1d30d0, items) == 0x08, "PriorityList1d30d0::items offset");

struct PriorityListOwner1d30d0
{
    std::uint64_t unk00;       // 00
    PriorityList1d30d0* list;  // 08

    void SortByPriority1d30d0();  // compared: 0x1d30d0
};
static_assert(offsetof(PriorityListOwner1d30d0, list) == 0x08, "PriorityListOwner1d30d0::list offset");
