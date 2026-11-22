// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf8e37e0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf8e37e0
{
public:
    DeletingLeaf8e37e0();
    virtual ~DeletingLeaf8e37e0();  // compared: 0x8e37e0 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x10];
};
static_assert(sizeof(DeletingLeaf8e37e0) == 0x18, "DeletingLeaf8e37e0 size");
