// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// 0x115190 std::_Tree::_Rrotate
// Adapted bodies: none.
#include "TreeKey115190.h"

using TreeVal115190 = std::_Tree_val<std::_Tree_simple_types<TreeKey115190>>;
template void TreeVal115190::_Rrotate(TreeVal115190::_Nodeptr);
