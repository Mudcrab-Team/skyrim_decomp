// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: ImageEffect1554640::Function1554640, treated as adapted: shaped like NiTArray::SetAt in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e include/NiTArray.h:93
// SPDX-License-Identifier: CC0-1.0
// 0x1554640 ImageEffect1554640::Function1554640
#include "ImageEffect1554640.h"

// Stores entry at entries[index], updating size and activeCount, and configures entry if non-null.
void ImageEffect1554640::Function1554640(std::uint32_t index, Entry_1554640* entry, std::uint32_t param)
{
    if (index >= size) {
        size = index + 1;
        if (entry != nullptr) {
            ++activeCount;
        }
    } else {
        Entry_1554640* existing = entries[index];
        if (entry != nullptr) {
            if (existing == nullptr) {
                ++activeCount;
            }
        } else if (existing != nullptr) {
            --activeCount;
        }
    }
    entries[index] = entry;
    if (entry != nullptr) {
        entry->Configure(param);
    }
}
