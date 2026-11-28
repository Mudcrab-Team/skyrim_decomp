// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Pop_heap_hole_by_index over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// StdPopHeap12bd30, StdPopHeap12bd30Compare: GUESS(low) STANDIN
// std::_Pop_heap_hole_by_index: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <algorithm>
#include <cstddef>

// Stand-in element and predicate types; the real types are unknown.
struct StdPopHeap12bd30
{
};
using StdPopHeap12bd30Compare = bool (*)(StdPopHeap12bd30*, StdPopHeap12bd30*);
