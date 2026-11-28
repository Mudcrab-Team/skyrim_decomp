// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// TreeKey1115b0: GUESS(low) STANDIN
#pragma once

#include <set>

struct TreeKey1115b0 {
    int value;
    bool operator<(const TreeKey1115b0& a_rhs) const { return value < a_rhs.value; }
};
