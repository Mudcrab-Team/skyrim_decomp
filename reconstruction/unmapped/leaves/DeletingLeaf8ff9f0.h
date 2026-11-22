// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf8ff9f0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf8ff9f0
{
public:
    DeletingLeaf8ff9f0();
    virtual ~DeletingLeaf8ff9f0();  // compared: 0x8ff9f0 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x48];
};
static_assert(sizeof(DeletingLeaf8ff9f0) == 0x50, "DeletingLeaf8ff9f0 size");
