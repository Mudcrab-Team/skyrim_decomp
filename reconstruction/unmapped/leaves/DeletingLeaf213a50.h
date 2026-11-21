// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: names from the inventory and the pinned image listing; the layout and destructor body are stand-ins written from the listing
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf213a50: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf213a50
{
public:
    DeletingLeaf213a50();
    virtual ~DeletingLeaf213a50();  // compared: 0x213a50 (scalar deleting destructor)
    // pad: GUESS(low); the class size is taken from the deleting destructor's delete size
    std::uint8_t pad[0x10];
};
static_assert(sizeof(DeletingLeaf213a50) == 0x18, "DeletingLeaf213a50 size");
