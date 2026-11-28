// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1163d0 FreeNode1163d0
// Adapted bodies: none.
#include "FreeFunction_1163d0.h"

// Destroys a tree node's value and returns the node to the allocator it is given.
void FreeNode1163d0(std::allocator<TreeNode1163d0>& a_alloc, TreeNode1163d0* a_node)
{
    a_alloc.destroy(a_node);
    a_alloc.deallocate(a_node, 1);
}
