// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Page_149e7f0, PageEntry_149e7f0, PageStorage_149e7f0, PageArray_149e7f0, Stack149e7f0, Data, Function149e7f0, size, data, page, unk08, inlineEntries, heapEntries, capacity, storage, unk00, pages, pageCount, target: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Page_149e7f0
{
    std::uint32_t size;    // 0x00
    std::uint8_t data[1];  // 0x04
};
static_assert(offsetof(Page_149e7f0, data) == 0x04, "data offset");

struct PageEntry_149e7f0
{
    Page_149e7f0* page;   // 0x00
    std::uint64_t unk08;  // 0x08
};
static_assert(sizeof(PageEntry_149e7f0) == 0x10, "PageEntry_149e7f0 size");

union PageStorage_149e7f0
{
    PageEntry_149e7f0 inlineEntries[3];
    PageEntry_149e7f0* heapEntries;
};

struct PageArray_149e7f0
{
    std::int32_t capacity;        // 0x00
    PageStorage_149e7f0 storage;  // 0x08

    const PageEntry_149e7f0* Data() const
    {
        const PageEntry_149e7f0* base = storage.inlineEntries;
        if (capacity >= 0) {
            base = storage.heapEntries;
        }
        return base;
    }
};

class Stack149e7f0
{
public:
    std::uint64_t unk00[3];  // 0x00
    PageArray_149e7f0 pages; // 0x18
    std::uint32_t pageCount; // 0x50

    std::uint32_t Function149e7f0(const std::uint8_t* target) const;
};
static_assert(offsetof(Stack149e7f0, pages) == 0x18, "pages offset");
static_assert(offsetof(Stack149e7f0, pageCount) == 0x50, "pageCount offset");
