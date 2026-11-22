// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf84dae0: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf84dae0
{
public:
    DeletingLeaf84dae0();
    virtual ~DeletingLeaf84dae0();  // compared: 0x84dae0 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x20];
};
static_assert(sizeof(DeletingLeaf84dae0) == 0x28, "DeletingLeaf84dae0 size");
