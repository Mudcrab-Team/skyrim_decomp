// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap: STANDIN COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// ScrapHeap::Functioncdfe10: GUESS(low)
// ScrapHeap::activeCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>


class ScrapHeap;
extern void FinishBlock(ScrapHeap*);
class ScrapHeap
{
public:
    void Functioncdfe10();
    std::uint8_t unknown0[120];
    std::uint32_t activeCount;
};
static_assert(offsetof(ScrapHeap, activeCount) == 120, "field offset");
