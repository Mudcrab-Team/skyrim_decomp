// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Push_heap_by_index over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// 0x12bf30 std::_Push_heap_by_index
// Adapted bodies: none
#include "StdPushHeap12bf30.h"

// The community name table calls this _Push_heap_by_index<> (a hint, not proof of the types).
template void std::_Push_heap_by_index<StdPushHeap12bf30**, StdPushHeap12bf30*, StdPushHeap12bf30Compare>(
    StdPushHeap12bf30**, std::ptrdiff_t, std::ptrdiff_t, StdPushHeap12bf30*&&, StdPushHeap12bf30Compare);
