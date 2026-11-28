// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x17e420 Func_17e420::ConstructRange
// Adapted bodies: none
#include "Func_17e420.h"

#include <new>

// Default-constructs count entries starting at startIndex.
void Func_17e420::ConstructRange(std::uint32_t startIndex, std::uint32_t count)
{
    Entry17e420* cur = &data[startIndex];
    for (std::uint32_t i = 0; i < count; ++i)
    {
        ::new (cur) Entry17e420();
        ++cur;
    }
}
