// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; explicit instantiation of a standard library template over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x13b3e0 std::allocator<Item13b3e0>::deallocate
// CI hash: 0x13b3e0 ?deallocate@?$allocator@UItem13b3e0@@@std@@QEAAXQEAUItem13b3e0@@_K@Z
// Adapted bodies: none
#include "Item13b3e0.h"


template void std::allocator<Item13b3e0>::deallocate(Item13b3e0* const, const std::size_t);
