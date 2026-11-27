// Source exposure: mixed.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ScrapHeap::Functioncdfe00: GUESS(low)
// ScrapHeap::unk78: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ScrapHeap
{
public:
    void Functioncdfe00();
    std::uint8_t unknown00[120];
    std::uint32_t unk78;
};
static_assert(offsetof(ScrapHeap, unk78) == 120, "field offset");
