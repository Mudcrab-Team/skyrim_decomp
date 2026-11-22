// Source exposure: mixed (community headers; compared functions from the pinned image).
// 0x666b40 compared function
// Code origin: SKELETON_TODO_CODE_ORIGIN (state the actual origin and any adaptation)
// SPDX-License-Identifier: CC0-1.0
// DeletingLeaf666b40: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DeletingLeaf666b40
{
public:
    DeletingLeaf666b40();
    virtual ~DeletingLeaf666b40();  // compared: 0x666b40

    // padding: GUESS(low); storage to the allocation size the deleting destructor frees
    std::uint8_t padding[0x20];  // 08
};
static_assert(sizeof(DeletingLeaf666b40) == 0x28, "deleting leaf size");
