// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// 0x1115b0 std::_Tree::_Rrotate
// Adapted bodies: none.
#include "TreeKey1115b0.h"

using TreeVal1115b0 = std::_Tree_val<std::_Tree_simple_types<TreeKey1115b0>>;
template void TreeVal1115b0::_Rrotate(TreeVal1115b0::_Nodeptr);
