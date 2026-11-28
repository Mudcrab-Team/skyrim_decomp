// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Insertion_sort_unchecked over a stand-in element type
// SPDX-License-Identifier: CC0-1.0
// StdInsertionSort12bb30, StdInsertionSort12bb30Compare: GUESS(low) STANDIN
#pragma once

#include <algorithm>
#include <cstddef>

// Stand-in element and predicate types; the real types are unknown.
struct StdInsertionSort12bb30
{
};
using StdInsertionSort12bb30Compare = bool (*)(StdInsertionSort12bb30*, StdInsertionSort12bb30*);
