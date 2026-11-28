// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// 0x128ef0 std::_Tree::_Rrotate
// Adapted bodies: none
#include "TreeKey128ef0.h"

using TreeVal128ef0 = std::_Tree_val<std::_Tree_simple_types<TreeKey128ef0>>;
template void TreeVal128ef0::_Rrotate(TreeVal128ef0::_Nodeptr);
