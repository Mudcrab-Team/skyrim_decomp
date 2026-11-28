// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x149e7f0 Stack149e7f0::Function149e7f0
// Adapted bodies: none
#include "Stack149e7f0.h"

// Returns the index of the page whose data range contains target, or pageCount if not found.
std::uint32_t Stack149e7f0::Function149e7f0(const std::uint8_t* target) const
{
    std::uint32_t index = 0;
    bool found = false;
    while (index < pageCount && !found) {
        const PageEntry_149e7f0* entries = pages.Data();
        const Page_149e7f0* page = entries[index].page;
        found = target >= page->data && target < page->data + page->size;
        if (!found) {
            ++index;
        }
    }
    return index;
}
