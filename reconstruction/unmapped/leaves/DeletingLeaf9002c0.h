// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf9002c0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf9002c0
{
public:
    DeletingLeaf9002c0();
    virtual ~DeletingLeaf9002c0();  // compared: 0x9002c0 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x30];
};
static_assert(sizeof(DeletingLeaf9002c0) == 0x38, "DeletingLeaf9002c0 size");
