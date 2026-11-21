// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf216300: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf216300
{
public:
    DeletingLeaf216300();
    virtual ~DeletingLeaf216300();  // compared: 0x216300 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x48];
};
static_assert(sizeof(DeletingLeaf216300) == 0x50, "DeletingLeaf216300 size");
