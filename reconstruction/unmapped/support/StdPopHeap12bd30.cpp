// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Pop_heap_hole_by_index over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x12bd30 std::_Pop_heap_hole_by_index
// Adapted bodies: none
#include "StdPopHeap12bd30.h"

// The community name table calls this _Pop_heap_hole_by_index<> (a hint, not proof of the types).
template void std::_Pop_heap_hole_by_index<StdPopHeap12bd30**, StdPopHeap12bd30*, StdPopHeap12bd30Compare>(
    StdPopHeap12bd30**, std::ptrdiff_t, std::ptrdiff_t, StdPopHeap12bd30*&&, StdPopHeap12bd30Compare);
