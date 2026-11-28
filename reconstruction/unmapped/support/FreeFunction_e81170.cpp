// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xe81170 Functione81170
// Adapted bodies: none
#include "FreeFunction_e81170.h"

// Ensures capacity for index, allocates a 0x1000-byte page at pages[index], and increments pageCount.
void Functione81170(PagedArray_e81170* array, std::size_t index)
{
    AllocDesc_e81170 desc;
    if (index >= array->capacity) {
        if (array->pages != nullptr) {
            array->pages = static_cast<void**>(
                g_heap_e81170->Realloc(array->pages, (array->capacity + 0x100) * sizeof(void*)));
        } else {
            desc.id = 0x105u;
            array->pages = static_cast<void**>(
                g_heap_e81170->AllocAutoHeap(array, 0x100 * sizeof(void*), &desc));
        }
        array->capacity += 0x100;
    }
    desc.id = 0x105u;
    array->pages[index] = g_heap_e81170->AllocAutoHeap(array, 0x1000, &desc);
    ++array->pageCount;
}
