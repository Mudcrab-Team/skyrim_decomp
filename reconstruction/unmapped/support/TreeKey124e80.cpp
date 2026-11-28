// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Tree::_Rrotate over a stand-in key type
// SPDX-License-Identifier: CC0-1.0
// 0x124e80 std::_Tree::_Rrotate
// Adapted bodies: none
#include "TreeKey124e80.h"

using TreeVal124e80 = std::_Tree_val<std::_Tree_simple_types<TreeKey124e80>>;
template void TreeVal124e80::_Rrotate(TreeVal124e80::_Nodeptr);
