// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xe2bf20 PagedPoolE2bf20::AllocatePage
// Adapted bodies: none.
#include "PagedPoolE2bf20.h"

void PagedPoolE2bf20::AllocatePage(std::size_t a_pageIndex)
{
    std::uint32_t tag;
    if (a_pageIndex >= pageCapacity) {
        if (pages != nullptr) {
            pages = static_cast<void**>(
                gPagedPoolAllocatorE2bf20->Reallocate(pages, (pageCapacity + 64) * sizeof(void*)));
        } else {
            tag = 0x8A;
            pages = static_cast<void**>(
                gPagedPoolAllocatorE2bf20->Allocate(this, 64 * sizeof(void*), &tag));
        }
        pageCapacity += 64;
    }

    tag = 0x8A;
    pages[a_pageIndex] = gPagedPoolAllocatorE2bf20->Allocate(this, 0x800, &tag);
    ++pageCount;
}
