// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf217870: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf217870
{
public:
    DeletingLeaf217870();
    virtual ~DeletingLeaf217870();  // compared: 0x217870 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x10];
};
static_assert(sizeof(DeletingLeaf217870) == 0x18, "DeletingLeaf217870 size");
