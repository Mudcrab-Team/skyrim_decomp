// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// TreeKey124e80: GUESS(low) STANDIN
#pragma once

#include <set>

struct TreeKey124e80
{
    int value;
    bool operator<(const TreeKey124e80& a_rhs) const { return value < a_rhs.value; }
};
