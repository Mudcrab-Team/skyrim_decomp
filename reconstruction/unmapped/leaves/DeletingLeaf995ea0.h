// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf995ea0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf995ea0
{
public:
    DeletingLeaf995ea0();
    virtual ~DeletingLeaf995ea0();  // compared: 0x995ea0 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x10];
};
static_assert(sizeof(DeletingLeaf995ea0) == 0x18, "DeletingLeaf995ea0 size");
